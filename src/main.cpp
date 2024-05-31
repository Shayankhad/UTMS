#include "global.hpp"

bool is_it_show_presented_course_type_two_command(string command){
    vector<string> commands;
    string word;
    stringstream ss;
    ss << command;
    int iteration = 0;

    while(getline(ss , word , ' ' )){
        if(!word.empty()){
            commands.push_back(word);
            iteration ++;
        }
    }

    if(iteration == 5){
        if((commands[0] == GET ) && (commands[1] == COURSES) && (commands[2] == QUESTION_MARK) && (commands[3] == ID)){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool is_presented_course_id_exist(vector<PresentedCourse *> presented_course , int target_presented_course_id){
    for(auto & presented_c : presented_course){
        if(presented_c->get_presented_course_id() == target_presented_course_id){
            return true;
        }
    }
    return false;
}

void show_presented_course_type_two_command(string command , vector<PresentedCourse *> presented_course){
    vector<string> commands;
    string word;
    stringstream ss;
    ss << command;
    while(getline(ss , word , ' ' )){
        if(!word.empty()){
            commands.push_back(word);
        }
    }

    if(check_number_type(commands[4]) != 1){
        throw BadRequest();
    }
    int target_presented_course_id = string_to_int(commands[4]); 

    if(!is_presented_course_id_exist(presented_course , target_presented_course_id)){
        throw NotFound();
    }

    for(auto & presented_c : presented_course){
        if(target_presented_course_id == presented_c->get_presented_course_id()){
            presented_c->show_type_2();
        }
    }

    throw OkExeption();
}


void run(vector<Student *> &students , vector<Course *> &courses, vector<Professor *> &professors , vector<PresentedCourse *> &presented_course , UtAccount *ut_account_ptr  ){
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
                int user_id = identify_user(students ,professors , ut_account_ptr);
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
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
    for(auto & x : presented_course){
        x->test_show();
    }
    deallocate(majors ,students , courses ,professors , ut_account_ptr ,presented_course );
    return 0;
}