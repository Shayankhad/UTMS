#include "global.hpp"

bool check_for_double_quatation(string command){
    stringstream ss;
    ss << command;
    string command_1;
    getline(ss , command_1 , ' ');
    string command_2;
    getline(ss , command_2 , ' ');
    string question_mark;
    getline(ss , question_mark , ' ');
    string arg_1;
    getline(ss , arg_1 , ' ');
    string arg_1_value;
    getline(ss , arg_1_value , '"');
    getline(ss , arg_1_value , '"');
    string arg_2;
    getline(ss , arg_2 , ' ');
    getline(ss , arg_2 , ' ');
    string test;
    if(getline(ss , test , '"')){
        if(!(test == "")){
            return false;
        }
    }
    string arg_2_value;
    int number_of_double_qoute = 0;
    while(getline(ss , arg_2_value , ' ')){
        for(char ch : arg_2_value){
            if(ch == '"'){
                number_of_double_qoute ++;
            }
        }
    }
    if(number_of_double_qoute == 0){
        return false;
    }
    return true;
}

bool is_it_post_command(string command){
    // POST post ? title “Good Day” message “Ye rooz joonane dige”
    // POST post ? message “Ye rooz joonane dige” title “Good Day”
    if(!check_for_double_quatation(command)){
        return false;
    }
    stringstream ss;
    ss << command;
    string command_1;
    getline(ss , command_1 , ' ');
    string command_2;
    getline(ss , command_2 , ' ');
    string question_mark;
    getline(ss , question_mark , ' ');
    string arg_1;
    getline(ss , arg_1 , ' ');
    string arg_1_value;
    getline(ss , arg_1_value , '"');
    getline(ss , arg_1_value , '"');
    string arg_2;
    getline(ss , arg_2 , ' ');
    getline(ss , arg_2 , ' ');
    string arg_2_value;
    getline(ss , arg_2_value , '"');
    getline(ss , arg_2_value , '"');
    string endline_test;
    getline(ss , endline_test , '\n');
    for(char c: endline_test){
        if((c != ' ')){
            return false;
        }
    }
    if((command_1 == POST) && (command_2 == POST_SECOND_COMMAND) && (question_mark == "?")){
        if(((arg_1 == TITLE) && (arg_2 == MESSAGE)) || ((arg_1 == MESSAGE) && (arg_2 == TITLE))){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

void post_command(string command, vector<Student *> &students, vector<Professor *> &professors, UtAccount *ut_account_ptr){
    int user_id = identify_user(students ,professors , ut_account_ptr);
    stringstream ss;
    ss << command;
    string begining;
    getline(ss , begining , ' ');
    getline(ss , begining , ' ');
    getline(ss , begining , ' ');
    string arg_1;
    getline(ss , arg_1 , ' ');
    string arg_1_value;
    getline(ss , arg_1_value , '"');
    getline(ss , arg_1_value , '"');
    string arg_2;
    getline(ss , arg_2 , ' ');
    getline(ss , arg_2 , ' ');
    string arg_2_value;
    getline(ss , arg_2_value , '"');
    getline(ss , arg_2_value , '"');
    if((arg_1 == TITLE) && (arg_2 == MESSAGE)){
        
        for(auto & student : students){
            if(student->get_id() == user_id){
                student->make_post(arg_1_value , arg_2_value);
                for(auto & s : students){
                    if(student->am_i_in_contact(s->get_id())){
                        s->add_notif(student->get_id() , student->get_name() , NEW_POST );
                    }   
                }
                for(auto & p : professors){ 
                    if(student->am_i_in_contact(p->get_id())){
                        p->add_notif(student->get_id() , student->get_name() , NEW_POST );
                    }
                }
                if(student->am_i_in_contact(ut_account_ptr->get_id())){
                    ut_account_ptr->add_notif(student->get_id() , student->get_name() , NEW_POST ); 
                }
            }
        }

        // for(auto & student : students){
        //     if(student->get_id() == user_id){
        //         student->make_post(arg_1_value , arg_2_value);
        //         for(auto & s : students){
        //             if(student->am_i_in_contact(s->get_id())){
        //                 s->add_notif(student->get_id() , student->get_name() , NEW_POST );
        //             }   
        //         }
        //         for(auto & p : professors){ 
        //             if(student->am_i_in_contact(p->get_id())){
        //                 p->add_notif(student->get_id() , student->get_name() , NEW_POST );
        //             }
        //         }
        //         if(student->am_i_in_contact(ut_account_ptr->get_id())){
        //             ut_account_ptr->add_notif(student->get_id() , student->get_name() , NEW_POST ); 
        //         }
        //     }
        // }



    }
    
    else if((arg_1 == MESSAGE) && (arg_2 == TITLE)){
    }
    // for (vector<int>::size_type i = 0 ; i < contacts.size() ; i++){
    //     cout << contacts[i] << endl;
    // }
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
    for(auto & s: students){
        s->show_my_posts();
        s->show_notif_vec();
    }
    for(auto & p: professors){
        p->show_my_posts();
        p->show_notif_vec();
    }
    ut_account_ptr->show_my_posts();
    ut_account_ptr->show_notif_vec();
    deallocate(majors ,students , courses ,professors , ut_account_ptr );
    return 0;
}