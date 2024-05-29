#include "global.hpp"


bool is_it_delete_post_command(string command){
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
        if((commands[0] == DELETE) && (commands[1] == POST_SECOND_COMMAND) && (commands[2] == QUESTION_MARK) && (commands[3] == ID)){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

void check_post_id_exist(int target_post_id ,vector<Student *> &students, vector<Professor *> &professors, UtAccount *ut_account_ptr ){
    bool does_post_id_match = false;
    int user_id = identify_user(students ,professors , ut_account_ptr);
    for(auto & student : students){
        if(student->get_id() == user_id){
            if(student->is_post_id_match(target_post_id)){
                does_post_id_match = true;
            }
        }
    }
    for(auto & professor : professors){
        if(professor->get_id() == user_id){
            if(professor->is_post_id_match(target_post_id)){
                does_post_id_match = true;
            }
        }
    }
    if(ut_account_ptr->get_id() == user_id){
        if(ut_account_ptr->is_post_id_match(target_post_id)){
            does_post_id_match = true;
        }
    }

    if(does_post_id_match == false){
        throw NotFound();
    }
}

void delete_post_command(string command, vector<Student *> &students, vector<Professor *> &professors, UtAccount *ut_account_ptr){
    //DELETE post ? id 3
    int user_id = identify_user(students ,professors , ut_account_ptr);
    vector<string> commands;
    string word;
    stringstream ss;
    ss << command;
    while(getline(ss , word , ' ' )){
        if(!word.empty()){
            commands.push_back(word);
        }
    }
    int target_post_id = string_to_int(commands[4]); 
    check_post_id_exist(target_post_id , students ,professors , ut_account_ptr);


    for(auto & student : students){
        if(student->get_id() == user_id){
            student->delete_post(target_post_id);
        }
    }
    for(auto & professor : professors){
        if(professor->get_id() == user_id){
            professor->delete_post(target_post_id);
        }
    }
    if(ut_account_ptr->get_id() == user_id){
        ut_account_ptr->delete_post(target_post_id);
    }

    throw OkExeption();

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