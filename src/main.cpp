#include "global.hpp"

void run(vector<Student *> &students , vector<Course *> &courses, vector<Professor *> &professors , vector<PresentedCourse *> &presented_course , UtAccount *ut_account_ptr ){
    set_ut_account_ptr_contacts(students ,professors , ut_account_ptr);
    string command;
    while (true)
    {
        try{
            getline(cin, command);
            if(command == "qq"){
                break;
            }



            check_for_four_commands(command);
            check_for_second_commands(command);
            check_for_quastion_mark(command);





            if(is_it_login_command(command)){
                if(is_anyone_loged_in(students ,professors , ut_account_ptr)){
                    throw PermissionDenied();
                }
                login_command(command ,students ,professors , ut_account_ptr);
            }






            if(is_it_logout_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                logout_command(students ,professors , ut_account_ptr);
            }






            if(is_it_connect_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                connect_command(command ,students ,professors , ut_account_ptr);
            }





            if(is_it_post_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                post_command(command ,students ,professors , ut_account_ptr);
            }





            if(is_it_delete_post_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                delete_post_command(command ,students ,professors , ut_account_ptr);
            }




            if(is_it_notificaiton_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                notificaiton_command(students ,professors , ut_account_ptr);
                continue;
            }




            if(is_it_course_offer_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                int user_id = identify_user(students ,professors , ut_account_ptr);
                if(user_id != 0){
                    throw PermissionDenied();
                }
                course_offer_command(command , students , courses , professors , presented_course , ut_account_ptr);
            }





            if(is_it_show_presented_course_type_one_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                show_presented_course_type_one_command(presented_course);
                continue;
            }




            if(is_it_show_presented_course_type_two_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                show_presented_course_type_two_command( command , presented_course);
                continue;
            }




            if(is_it_take_course_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                int user_id = identify_user(students ,professors , ut_account_ptr);
                if(!is_it_student(user_id , students)){
                    throw PermissionDenied();
                }
                take_course_command(command ,students , courses , professors , presented_course , ut_account_ptr , user_id );
            }







            if(is_it_delete_student_course(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                int user_id = identify_user(students ,professors , ut_account_ptr);
                if(!is_it_student(user_id , students)){
                    throw PermissionDenied();
                }
                delete_student_course(command , students , professors , ut_account_ptr , user_id);
            }





            if(is_it_show_my_courses_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                int user_id = identify_user(students ,professors , ut_account_ptr);
                if(!is_it_student(user_id , students)){
                    throw PermissionDenied();
                }
                show_my_courses_command(user_id , students , presented_course);
                continue;
            }





            // end
            throw BadRequest();

        }
        catch(const MyException& e){
            cout <<e.what() << endl;
            
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
    extract_csv(majors , students , courses , professors , argv[1] , argv[2] , argv[3] , argv[4]);
    run(students , courses , professors , presented_course , ut_account_ptr);
    for(auto & x : students){
        x->show_token_courses();
    }
    deallocate(majors ,students , courses ,professors , ut_account_ptr ,presented_course );
    return 0;
}