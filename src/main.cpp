#include "global.hpp"

bool is_it_show_course_post_command(string command){
    vector<string> commands;
    stringstream ss;
    ss << command;
    string word;
    int iteration = 0;
    while (getline(ss, word, ' '))
    {
        if (!(word == ""))
        {
            commands.push_back(word);
            iteration++;
        }
    }
    if (iteration == 7)
    {
        if (((commands[0] == GET) && (commands[1] == COURSE_POST) && (commands[2] == "?") && (commands[3] == ID) && (commands[5] == POST_ID)) || ((commands[0] == GET) && (commands[1] == COURSE_POST) && (commands[2] == "?") && (commands[3] == POST_ID) && (commands[5] == ID)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

vector<vector<string>> sort_show_course_post_args(vector<vector<string>> un_sorted){
    vector<vector<string>> sorted(2);
    for(vector<std::vector<std::__cxx11::basic_string<char> > >::size_type i = 0 ; i < un_sorted.size() ; i++){
        if(un_sorted[i][0] == ID){
            sorted[0] =un_sorted[i];
        }
        if(un_sorted[i][0] == POST_ID){
            sorted[1] =un_sorted[i];
        }
    }
    return sorted;
}

void show_course_post_command(int user_id , string command , vector<PresentedCourse *> presented_course , vector<Student *> students , vector<Professor *> professors){
    // GET course_post ? id 7 post_id 2
    vector<string> commands;
    stringstream ss;
    ss << command;
    string word;
    int iteration = 0;
    while (getline(ss, word, ' '))
    {
        if (!(word == ""))
        {
            commands.push_back(word);
            iteration++;
        }
    }
    vector<vector<string>> command_args;
    command_args.push_back({commands[3] , commands[4]});
    command_args.push_back({commands[5] , commands[6]});
    command_args = sort_show_course_post_args(command_args);
    if(check_number_type(commands[4]) != 1){
        throw BadRequest();
    }
    int id = string_to_int(commands[4]);
    if(check_number_type(commands[6]) != 1){
        throw BadRequest();
    }
    int post_id = string_to_int(commands[6]);

    if(!is_presented_course_id_exist(presented_course , id)){
        throw NotFound();
    }
    PresentedCourse * presented_course_ptr = find_PresentedCourse(id , presented_course); 
    if(!presented_course_ptr->does_post_exist(post_id)){
        throw NotFound();
    }

    bool does_id_has_per = false;

    for(auto & student : students){
        if(student->get_id() == user_id){
            vector<int> tooken_course;
            tooken_course = student->get_token_courses();
            for(auto & a : tooken_course){
                if(a == id){
                    does_id_has_per = true;
                }
            }
        }
    }

    for(auto & professor : professors){
        if(professor->get_id() == user_id){
            vector<int> tooken_course;
            tooken_course = professor->get_token_courses();
            for(auto & a : tooken_course){
                if(a == id){
                    does_id_has_per = true;
                }
            }
        }
    }
    if(!does_id_has_per){
        throw PermissionDenied();
    }   

    presented_course_ptr->show_specific_post(post_id);
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