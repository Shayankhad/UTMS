#include "global.hpp"

bool check_make_course_post_type_one_args(vector<vector<string>> commands){
    bool does_it_have_id = false;
    for(auto & layer_1 : commands){
        if(layer_1[0] == ID){
            does_it_have_id = true;
        }
    }
    bool does_it_have_title = false;
    for(auto & layer_1 : commands){
        if(layer_1[0] == TITLE){
            does_it_have_title = true;
        }
    }
    bool does_it_have_message = false;
    for(auto & layer_1 : commands){
        if(layer_1[0] == MESSAGE){
            does_it_have_message = true;
        }
    }
    return (does_it_have_id && does_it_have_title && does_it_have_message);
}
 
bool is_it_make_course_post_command_type_one(string command){
    
    string help_str;
    stringstream ss;
    ss << command;
    string command_1;
    getline(ss , command_1 , ' ');
    string command_2;
    getline(ss , command_2 , ' ');
    string q_mark;
    getline(ss , q_mark , ' ');
    if((command_1 != POST) || (command_2 != COURSE_POST ) || (q_mark != QUESTION_MARK)){
        return false;
    }
    vector<char> command_char;
    for(std::__cxx11::basic_string<char>::size_type i = 0 ; i < command.size() ; i++ ){
        if(!(command[i] == ' ')){
            command_char.push_back(command[i]);
        }
    }
    string arg_sample;
    string arg_sample_val;
    string space_sample_val;
    vector<vector<string>> commands(3);
    for(int i = 0 ; i < 3 ; i++){
        getline(ss , arg_sample , ' ');
        if(arg_sample.empty()){
            return false;
        }
        if(arg_sample != ID){
            getline(ss, arg_sample_val , '"');
            getline(ss, arg_sample_val , '"');
            getline(ss, space_sample_val , ' ');
        }else{
            getline(ss , arg_sample_val , ' ' );
        }
        if(arg_sample.empty()){
            return false;
        }
        if(arg_sample_val.empty()){
            return false;
        }
        commands[i]= {arg_sample , arg_sample_val};
    }

    if(commands[2][0] != ID){
        if(!(command_char[command_char.size() - 1] == '"')){
            return false;
        }
    }

    if(!check_make_course_post_type_one_args(commands)){
        return false;
    }
    return true;
}



vector<vector<string>> sort_course_post_type_one_command(vector<vector<string>> un_sorted){
    vector<vector<string>> sorted(3);
    for(vector<std::vector<std::__cxx11::basic_string<char> > >::size_type i = 0 ; i < un_sorted.size() ; i++){
        if(un_sorted[i][0] == ID){
            sorted[0] =un_sorted[i];
        }
        if(un_sorted[i][0] == TITLE){
            sorted[1] =un_sorted[i];
        }
        if(un_sorted[i][0] == MESSAGE){
            sorted[2] =un_sorted[i];
        }
    }
    return sorted;
}

vector<int> get_all_presented_courses(vector<Professor *> &professors){
    vector<int> all_courses;
    for(auto & professor : professors){
        for(auto & x : professor->get_token_courses()){
            all_courses.push_back(x);
        }
    }
    return all_courses;
}


void post_course_notif_handle(int user_id , int presented_course_id , string presented_course_name, vector<Student *> &students , vector<Professor *> &professors){
    for(auto &student : students){
        for(auto & int_courses : student->get_token_courses()){
            if(int_courses == presented_course_id){
                if(student->get_id() != user_id){
                    student->add_notif(presented_course_id , presented_course_name , NEW_COURSE_POST);
                }
            }
        }
    }

    for(auto & professor : professors){
        for(auto & int_courses : professor->get_token_courses()){
            if(int_courses == presented_course_id){
                if(professor->get_id() != user_id){
                    professor->add_notif(presented_course_id , presented_course_name , NEW_COURSE_POST);
                }
            }
        }
    }
}


void make_course_post_command_type_one(int user_id,string command , vector<Student *> &students , vector<Professor *> &professors , vector<PresentedCourse *> &presented_course ){
    // POST course_post ? id 4 title “Homework 6” message “Phase 2”
    string arg_sample;
    string arg_sample_val;
    string space_sample_val;
    stringstream ss;
    ss << command;
    getline(ss , space_sample_val , ' ');
    getline(ss , space_sample_val , ' ');
    getline(ss , space_sample_val , ' ');
    vector<vector<string>> commands(3);
    for(int i = 0 ; i < 3 ; i++){
        getline(ss , arg_sample , ' ');
        if(arg_sample != ID){
            getline(ss, arg_sample_val , '"');
            getline(ss, arg_sample_val , '"');
            getline(ss, space_sample_val , ' ');
        }else{
            getline(ss , arg_sample_val , ' ' );
        }
        commands[i]= {arg_sample , arg_sample_val};
    }
    commands = sort_course_post_type_one_command(commands); 
    if (user_id == 0){
        throw PermissionDenied();
    }
    int presnted_course_id = string_to_int(commands[0][1]);
    string post_title = commands[1][1];
    string post_message = commands[2][1];
    string author_name;
    vector <int> all_courses;
    all_courses = get_all_presented_courses(professors);
    bool does_id_exist = false;
    bool does_id_has_per = false;

    for(auto & student : students){
        if(student->get_id() == user_id){
            author_name = student->get_name();
            for(auto & x : all_courses){
                if(x == presnted_course_id){
                    does_id_exist = true;
                }
            }
            vector<int> tooken_course;
            tooken_course = student->get_token_courses();
            for(auto & a : tooken_course){
                if(a == presnted_course_id){
                    does_id_has_per = true;
                }
            }
        }
    }

    for(auto & professor : professors){
        if(professor->get_id() == user_id){
            author_name = professor->get_name();
            for(auto & x : all_courses){
                if(x == presnted_course_id){
                    does_id_exist = true;
                }
            }
            vector<int> tooken_course;
            tooken_course = professor->get_token_courses();
            for(auto & a : tooken_course){
                if(a == presnted_course_id){
                    does_id_has_per = true;
                }
            }
        }
    }

    if(!does_id_exist){
        throw NotFound();
    }

    if(!does_id_has_per){
        throw PermissionDenied();
    }

    PresentedCourse * presented_course_ptr = find_PresentedCourse(presnted_course_id , presented_course);
    string presented_course_name = presented_course_ptr->get_course_name();
    presented_course_ptr->add_course_post(user_id , author_name , presnted_course_id , presented_course_name , post_title , post_message);
    post_course_notif_handle(user_id , presnted_course_id , presented_course_name , students , professors);
    throw OkExeption();
}

bool check_make_course_post_type_two_args(vector<vector<string>> commands){
    bool does_it_have_id = false;
    for(auto & layer_1 : commands){
        if(layer_1[0] == ID){
            does_it_have_id = true;
        }
    }
    bool does_it_have_title = false;
    for(auto & layer_1 : commands){
        if(layer_1[0] == TITLE){
            does_it_have_title = true;
        }
    }
    bool does_it_have_message = false;
    for(auto & layer_1 : commands){
        if(layer_1[0] == MESSAGE){
            does_it_have_message = true;
        }
    }
    bool does_it_have_image = false;
    for(auto & layer_1 : commands){
        if(layer_1[0] == IMAGE){
            does_it_have_image = true;
        }
    }

    return (does_it_have_id && does_it_have_title && does_it_have_message && does_it_have_image);
}

bool is_it_make_course_post_command_type_two(string command){
    string help_str;
    stringstream ss;
    ss << command;
    string command_1;
    getline(ss , command_1 , ' ');
    string command_2;
    getline(ss , command_2 , ' ');
    string q_mark;
    getline(ss , q_mark , ' ');
    if((command_1 != POST) || (command_2 != COURSE_POST ) || (q_mark != QUESTION_MARK)){
        return false;
    }
    vector<char> command_char;
    for(std::__cxx11::basic_string<char>::size_type i = 0 ; i < command.size() ; i++ ){
        if(!(command[i] == ' ')){
            command_char.push_back(command[i]);
        }
    }
    string arg_sample;
    string arg_sample_val;
    string space_sample_val;
    vector<vector<string>> commands(4);
    for(int i = 0 ; i < 4 ; i++){
        getline(ss , arg_sample , ' ');
        if(arg_sample.empty()){
            return false;
        }
        if((arg_sample != ID) && (arg_sample != IMAGE)){
            getline(ss, arg_sample_val , '"');
            getline(ss, arg_sample_val , '"');
            getline(ss, space_sample_val , ' ');
        }else{
            getline(ss , arg_sample_val , ' ' );
        }
        if(arg_sample.empty()){
            return false;
        }
        if(arg_sample_val.empty()){
            return false;
        }
        commands[i]= {arg_sample , arg_sample_val};
    }

    if((commands[3][0] != ID) && (commands[3][0] != IMAGE)){
        if(!(command_char[command_char.size() - 1] == '"')){
            return false;
        }
    }

    if(!check_make_course_post_type_two_args(commands)){
        return false;
    }
    return true;
}


vector<vector<string>> sort_course_post_type_two_command(vector<vector<string>> un_sorted){
    vector<vector<string>> sorted(4);
    for(vector<std::vector<std::__cxx11::basic_string<char> > >::size_type i = 0 ; i < un_sorted.size() ; i++){
        if(un_sorted[i][0] == ID){
            sorted[0] =un_sorted[i];
        }
        if(un_sorted[i][0] == TITLE){
            sorted[1] =un_sorted[i];
        }
        if(un_sorted[i][0] == MESSAGE){
            sorted[2] =un_sorted[i];
        }
        if(un_sorted[i][0] == IMAGE){
            sorted[3] =un_sorted[i];
        }
    }
    return sorted;
}

void make_course_post_command_type_two(int user_id,string command , vector<Student *> &students , vector<Professor *> &professors , vector<PresentedCourse *> &presented_course ){
    // POST course_post ? id 2 title "asd" message "qwe" image rtfd
    string arg_sample;
    string arg_sample_val;
    string space_sample_val;
    stringstream ss;
    ss << command;
    getline(ss , space_sample_val , ' ');
    getline(ss , space_sample_val , ' ');
    getline(ss , space_sample_val , ' ');
    vector<vector<string>> commands(4);
    for(int i = 0 ; i < 4 ; i++){
        getline(ss , arg_sample , ' ');
        if((arg_sample != ID) && (arg_sample != IMAGE)){
            getline(ss, arg_sample_val , '"');
            getline(ss, arg_sample_val , '"');
            getline(ss, space_sample_val , ' ');
        }else{
            getline(ss , arg_sample_val , ' ' );
        }
        commands[i]= {arg_sample , arg_sample_val};
    }
    commands = sort_course_post_type_two_command(commands); 
    if (user_id == 0){
        throw PermissionDenied();
    }
    int presnted_course_id = string_to_int(commands[0][1]);
    string post_title = commands[1][1];
    string post_message = commands[2][1];
    string post_image = commands[3][1];
    string author_name;
    vector <int> all_courses;
    all_courses = get_all_presented_courses(professors);
    bool does_id_exist = false;
    bool does_id_has_per = false;

    for(auto & student : students){
        if(student->get_id() == user_id){
            author_name = student->get_name();
            for(auto & x : all_courses){
                if(x == presnted_course_id){
                    does_id_exist = true;
                }
            }
            vector<int> tooken_course;
            tooken_course = student->get_token_courses();
            for(auto & a : tooken_course){
                if(a == presnted_course_id){
                    does_id_has_per = true;
                }
            }
        }
    }

    for(auto & professor : professors){
        if(professor->get_id() == user_id){
            author_name = professor->get_name();
            for(auto & x : all_courses){
                if(x == presnted_course_id){
                    does_id_exist = true;
                }
            }
            vector<int> tooken_course;
            tooken_course = professor->get_token_courses();
            for(auto & a : tooken_course){
                if(a == presnted_course_id){
                    does_id_has_per = true;
                }
            }
        }
    }

    if(!does_id_exist){
        throw NotFound();
    }

    if(!does_id_has_per){
        throw PermissionDenied();
    }

    PresentedCourse * presented_course_ptr = find_PresentedCourse(presnted_course_id , presented_course);
    string presented_course_name = presented_course_ptr->get_course_name();
    presented_course_ptr->add_course_post_with_image(user_id , author_name , presnted_course_id , presented_course_name , post_title , post_message , post_image);
    post_course_notif_handle(user_id , presnted_course_id , presented_course_name , students , professors);
    throw OkExeption();
}


void run(vector<Student *> &students, vector<Course *> &courses, vector<Professor *> &professors, vector<PresentedCourse *> &presented_course, UtAccount *ut_account_ptr, vector<Major *> &majors)
{
    set_ut_account_ptr_contacts(students, professors, ut_account_ptr);
    string command;
    while (true)
    {
        try
        {
            getline(cin, command);
            if (command == "qq")
            {
                break;
            }
            check_for_four_commands(command);
            check_for_second_commands(command);
            check_for_quastion_mark(command);

            if (is_it_login_command(command))
            {
                if (is_anyone_loged_in(students, professors, ut_account_ptr))
                {
                    throw PermissionDenied();
                }
                login_command(command, students, professors, ut_account_ptr);
            }

            if (is_it_logout_command(command))
            {
                if (!(is_anyone_loged_in(students, professors, ut_account_ptr)))
                {
                    throw PermissionDenied();
                }
                logout_command(students, professors, ut_account_ptr);
            }

            if (is_it_connect_command(command))
            {
                if (!(is_anyone_loged_in(students, professors, ut_account_ptr)))
                {
                    throw PermissionDenied();
                }
                connect_command(command, students, professors, ut_account_ptr);
            }

            if (is_it_post_command(command))
            {
                if (!(is_anyone_loged_in(students, professors, ut_account_ptr)))
                {
                    throw PermissionDenied();
                }
                post_command(command, students, professors, ut_account_ptr);
            }

            if (is_it_delete_post_command(command))
            {
                if (!(is_anyone_loged_in(students, professors, ut_account_ptr)))
                {
                    throw PermissionDenied();
                }
                delete_post_command(command, students, professors, ut_account_ptr);
            }

            if (is_it_notificaiton_command(command))
            {
                if (!(is_anyone_loged_in(students, professors, ut_account_ptr)))
                {
                    throw PermissionDenied();
                }
                notificaiton_command(students, professors, ut_account_ptr);
                continue;
            }

            if (is_it_course_offer_command(command))
            {
                if (!(is_anyone_loged_in(students, professors, ut_account_ptr)))
                {
                    throw PermissionDenied();
                }
                int user_id = identify_user(students, professors, ut_account_ptr);
                if (user_id != 0)
                {
                    throw PermissionDenied();
                }
                course_offer_command(command, students, courses, professors, presented_course, ut_account_ptr);
            }

            if (is_it_show_presented_course_type_one_command(command))
            {
                if (!(is_anyone_loged_in(students, professors, ut_account_ptr)))
                {
                    throw PermissionDenied();
                }
                show_presented_course_type_one_command(presented_course);
                continue;
            }

            if (is_it_show_presented_course_type_two_command(command))
            {
                if (!(is_anyone_loged_in(students, professors, ut_account_ptr)))
                {
                    throw PermissionDenied();
                }
                show_presented_course_type_two_command(command, presented_course);
                continue;
            }

            if (is_it_take_course_command(command))
            {
                if (!(is_anyone_loged_in(students, professors, ut_account_ptr)))
                {
                    throw PermissionDenied();
                }
                int user_id = identify_user(students, professors, ut_account_ptr);
                if (!is_it_student(user_id, students))
                {
                    throw PermissionDenied();
                }
                take_course_command(command, students, courses, professors, presented_course, ut_account_ptr, user_id);
            }

            if (is_it_delete_student_course(command))
            {
                if (!(is_anyone_loged_in(students, professors, ut_account_ptr)))
                {
                    throw PermissionDenied();
                }
                int user_id = identify_user(students, professors, ut_account_ptr);
                if (!is_it_student(user_id, students))
                {
                    throw PermissionDenied();
                }
                delete_student_course(command, students, professors, ut_account_ptr, user_id);
            }

            if (is_it_show_my_courses_command(command))
            {
                if (!(is_anyone_loged_in(students, professors, ut_account_ptr)))
                {
                    throw PermissionDenied();
                }
                int user_id = identify_user(students, professors, ut_account_ptr);
                if (!is_it_student(user_id, students))
                {
                    throw PermissionDenied();
                }
                show_my_courses_command(user_id, students, presented_course);
                continue;
            }

            if (is_it_show_personal_page_command(command))
            {
                if (!(is_anyone_loged_in(students, professors, ut_account_ptr)))
                {
                    throw PermissionDenied();
                }
                show_personal_page_command(command, students, professors, ut_account_ptr, presented_course, majors);
                continue;
            }

            if (is_it_show_post_command(command))
            {
                if (!(is_anyone_loged_in(students, professors, ut_account_ptr)))
                {
                    throw PermissionDenied();
                }
                show_post_command(command, students, professors, ut_account_ptr, presented_course, majors);
                continue;
            }



            if(is_it_post_image_command(command)){
                if (!(is_anyone_loged_in(students, professors, ut_account_ptr)))
                {
                    throw PermissionDenied();
                }
                int user_id = identify_user(students, professors, ut_account_ptr);
                post_image_command(user_id , command , students , professors , ut_account_ptr);
            }





            if(is_it_add_profile_photo_command(command)){
                if (!(is_anyone_loged_in(students, professors, ut_account_ptr)))
                {
                    throw PermissionDenied();
                }
                int user_id = identify_user(students, professors, ut_account_ptr);
                add_profile_photo_command(command , user_id , students , professors , ut_account_ptr);
            }




            if(is_it_make_course_post_command_type_one(command)){
                if (!(is_anyone_loged_in(students, professors, ut_account_ptr)))
                {
                    throw PermissionDenied();
                }
                int user_id = identify_user(students, professors, ut_account_ptr);
                make_course_post_command_type_one(user_id , command , students , professors , presented_course);
            }



            if (is_it_make_course_post_command_type_two(command)){
                if (!(is_anyone_loged_in(students, professors, ut_account_ptr)))
                {
                    throw PermissionDenied();
                }
                int user_id = identify_user(students, professors, ut_account_ptr);
                make_course_post_command_type_two(user_id , command , students , professors , presented_course);
            }





            throw BadRequest();
        }
        catch (const MyException &exept)
        {
            cout << exept.what() << endl;
        }
    }
}

int main(int argc, char *argv[])
{
    argc++;
    argc--;
    vector<Major *> majors;
    vector<Student *> students;
    vector<Course *> courses;
    vector<Professor *> professors;
    vector<PresentedCourse *> presented_course;
    UtAccount *ut_account_ptr = new UtAccount();
    extract_csv(majors, students, courses, professors, argv[1], argv[2], argv[3], argv[4]);
    run(students, courses, professors, presented_course, ut_account_ptr, majors);
    for(auto & s : presented_course){
        s->show_post_images();
    }
    deallocate(majors, students, courses, professors, ut_account_ptr, presented_course);
    return 0;
}