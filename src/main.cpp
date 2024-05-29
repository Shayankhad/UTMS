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

void run(vector<Student *> &students , vector<Professor *> &professors , UtAccount *ut_account_ptr){
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




            cout << is_it_notificaiton_command(command) << endl;




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

    // first show posts
    for(auto & s: students){
        s->show_my_posts();
    }
    for(auto & p: professors){
        p->show_my_posts();
    }
    ut_account_ptr->show_my_posts();

    // second show notif

    for(auto & s: students){
        s->show_notif_vec();
    }
    for(auto & p: professors){
        p->show_notif_vec();
    }
    ut_account_ptr->show_notif_vec();
    deallocate(majors ,students , courses ,professors , ut_account_ptr );
    return 0;
}