#include "global.hpp"

bool check_ta_form_args(vector<vector<string>> commands){
    bool does_it_have_course_id = false;
    for(auto & layer_1 : commands){
        if(layer_1[0] == COURSE_ID){
            does_it_have_course_id = true;
        }
    }
    bool does_it_have_message = false;
    for(auto & layer_1 : commands){
        if(layer_1[0] == MESSAGE){
            does_it_have_message = true;
        }
    }
    return (does_it_have_course_id && does_it_have_message);
}

bool is_it_ta_form_command(string command){
    string help_str;
    stringstream ss;
    ss << command;
    string command_1;
    getline(ss , command_1 , ' ');
    string command_2;
    getline(ss , command_2 , ' ');
    string q_mark;
    getline(ss , q_mark , ' ');
    if((command_1 != POST) || (command_2 != TA_FORM) || (q_mark != QUESTION_MARK)){
        return false;
    }
    vector<char> command_char;

    string arg_sample;
    string arg_sample_val;
    string space_sample_val;
    vector<vector<string>> commands(2);
    // POST ta_form ? course_id 2 message ”TA for designing project”
    for(int i = 0 ; i < 2 ; i++){
        getline(ss , arg_sample , ' ');
        if(arg_sample.empty()){
            return false;
        }
        if(arg_sample != COURSE_ID){
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
    
    while(getline(ss , space_sample_val , ' ')){
        if((space_sample_val != " ") && (space_sample_val != "") ){
            return false;
        }
    }

    for(std::__cxx11::basic_string<char>::size_type i = 0 ; i < command.size() ; i++ ){
        if(!(command[i] == ' ')){
            command_char.push_back(command[i]);
        }
    }
    if(commands[1][0] != COURSE_ID){
        if(!(command_char[command_char.size() - 1] == '"')){
            return false;
        }
    }


    if(!check_ta_form_args(commands)){
        return false;
    }
    return true;
}


vector<vector<string>> sort_ta_form_args(vector<vector<string>> un_sorted){
    vector<vector<string>> sorted(2);
    for(vector<std::vector<std::__cxx11::basic_string<char> > >::size_type i = 0 ; i < un_sorted.size() ; i++){
        if(un_sorted[i][0] == COURSE_ID){
            sorted[0] = un_sorted[i];
        }
        if(un_sorted[i][0] == MESSAGE){
            sorted[1] = un_sorted[i];
        }
    }
    return sorted;
}

void ta_form_command(string command){
    // POST ta_form ? course_id 2 message ”TA for designing project”
    string arg_sample;
    string arg_sample_val;
    string space_sample_val;
    vector<vector<string>> commands(2);
    stringstream ss;
    ss << command;
    getline(ss , space_sample_val , ' ');
    getline(ss , space_sample_val , ' ');
    getline(ss , space_sample_val , ' ');
    for(int i = 0 ; i < 2 ; i++){
        getline(ss , arg_sample , ' ');
        if(arg_sample != COURSE_ID){
            getline(ss, arg_sample_val , '"');
            getline(ss, arg_sample_val , '"');
            getline(ss, space_sample_val , ' ');
        }else{
            getline(ss , arg_sample_val , ' ' );
        }
        commands[i]= {arg_sample , arg_sample_val};
    }
    commands = sort_ta_form_args(commands);
    for(auto & a : commands){
        for(auto & b : a){
            cout << b << endl;
        }
    }
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



            if(is_it_show_course_channel_command(command)){
                if (!(is_anyone_loged_in(students, professors, ut_account_ptr)))
                {
                    throw PermissionDenied();
                }
                int user_id = identify_user(students, professors, ut_account_ptr);
                show_course_channel_command(command , user_id , students , professors , presented_course);
                continue;
            }



            if(is_it_show_course_post_command(command)){
                if (!(is_anyone_loged_in(students, professors, ut_account_ptr)))
                {
                    throw PermissionDenied();
                }
                int user_id = identify_user(students, professors, ut_account_ptr);
                show_course_post_command(user_id , command  ,presented_course , students , professors);
                continue;
            }



            cout << is_it_ta_form_command(command) << endl;


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
    // for(auto & s : presented_course){
    //     s->show_post_images();
    // }
    deallocate(majors, students, courses, professors, ut_account_ptr, presented_course);
    return 0;
}