#include "global.hpp"

bool is_it_notificaiton_command(string command){
    vector<string> commands;
    stringstream ss;
    ss << command;
    string word;
    int iteration = 0 ;
    while (getline(ss, word, ' '))
    {
        if(!(word == "")){
            commands.push_back(word);
            iteration ++;
        }
    }
    if(iteration == 3){
        if((commands[0] == GET) && (commands[1] == NOTIFICATION) && (commands[2] == "?")){
            return true;
        }else {
            return false;
        }
    }else {
        return false;
    }
}

void notificaiton_command(vector<Student *> &students , vector<Professor *> &professors , UtAccount *ut_account_ptr){
    bool is_notif_printed = false;
    int user_id = identify_user(students ,professors , ut_account_ptr);
    for(auto & student: students){
        if(student->get_id() == user_id){
            if(!student->is_notifications_empty()){
                is_notif_printed = true;
                student->show_notif_vec();
            }
        }
    }
    for(auto & professor: professors){
        if(professor->get_id() == user_id){
            if(!professor->is_notifications_empty()){
                is_notif_printed = true;
                professor->show_notif_vec();
            }
        }
    }
    if(ut_account_ptr->get_id() == user_id){
        if(!ut_account_ptr->is_notifications_empty()){
            is_notif_printed = true;
            ut_account_ptr->show_notif_vec();
        }
    }
    if(!is_notif_printed){
        throw Empty();
    }
}
void set_ut_account_ptr_contacts(vector<Student *> &students , vector<Professor *> &professors , UtAccount *ut_account_ptr){
    for(auto & student : students){
        ut_account_ptr->add_contacts(student->get_id());
        student->add_contacts(ut_account_ptr->get_id());
    }
    for(auto & professor : professors){
        ut_account_ptr->add_contacts(professor->get_id());
        professor->add_contacts(ut_account_ptr->get_id());
    }
}
void run(vector<Student *> &students , vector<Professor *> &professors , UtAccount *ut_account_ptr){
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
    UtAccount *ut_account_ptr = new UtAccount();
    extract_majors_csv(argv[1], majors);
    extract_students_csv(argv[2], students);
    extract_courses_csv(argv[3], courses);
    extract_professors_csv(argv[4], professors);
    run(students ,professors , ut_account_ptr);
    deallocate(majors ,students , courses ,professors , ut_account_ptr );
    return 0;
}