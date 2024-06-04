#include "global.hpp"

vector<vector<string>> sort_post_command(string arg_1 , string arg_2 , string arg_3
, string arg_1_value , string arg_2_value , string arg_3_value){
    vector<vector<string>> un_sorted(3);
    un_sorted.push_back({arg_1 , arg_1_value});
    un_sorted.push_back({arg_2 , arg_2_value});
    un_sorted.push_back({arg_3 , arg_3_value});
    vector<vector<string>> sorted(3);
    for(std::vector<std::vector<std::__cxx11::basic_string<char> > >::size_type i = 0 ; i < un_sorted.size() ; i++){
        if(un_sorted[i][0] == TITLE){
            sorted[0] =un_sorted[i];
        }
        if(un_sorted[i][0] == MESSAGE){
            sorted[1] =un_sorted[i];
        }
        if(un_sorted[i][0] == IMAGE){
            sorted[2] =un_sorted[i];
        }
    }
    return sorted;
}

void is_it_post_image_command(string command){
    string help_str;
    stringstream ss;
    ss << command;
    string command_1;
    getline(ss , command_1 , ' ');
    string command_2;
    getline(ss , command_2 , ' ');
    string q_mark;
    getline(ss , q_mark , ' ');
    string arg_1;
    getline(ss , arg_1 , ' ');
    string arg_1_value;
    if(arg_1 == IMAGE){
        getline(ss , arg_1_value , ' ');
    }else{
        getline(ss, arg_1_value, '"');
        getline(ss, arg_1_value, '"');
        getline(ss, help_str, ' ');
    }
    string arg_2;
    getline(ss , arg_2 , ' ');
    string arg_2_value;
    if(arg_2 == IMAGE){
        getline(ss , arg_2_value , ' ');
    }else{
        getline(ss, arg_2_value, '"');
        getline(ss, arg_2_value, '"');
        getline(ss, help_str, ' ');
    }
    string arg_3;
    getline(ss , arg_3 , ' ');
    string arg_3_value;
    if(arg_3 == IMAGE){
        getline(ss , arg_3_value , ' ');
    }else{
        getline(ss, arg_3_value, '"');
        getline(ss, arg_3_value, '"');
        getline(ss, help_str, ' ');
    }
    vector<vector<string>> args; 
    args = sort_post_command(arg_1 , arg_2 , arg_3 , arg_1_value , arg_2_value , arg_3_value);
    


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




            is_it_post_image_command(command);




            throw BadRequest();
        }
        catch (const MyException &e)
        {
            cout << e.what() << endl;
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
    deallocate(majors, students, courses, professors, ut_account_ptr, presented_course);
    return 0;
}