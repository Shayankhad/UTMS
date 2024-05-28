#include "global.hpp"


bool is_it_post_command(string command){
    // POST post ? title “Good Day” message “Ye rooz joonane dige”

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
                logout_command(command ,students ,professors , ut_account_ptr);
            }






            if(is_it_connect_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                connect_command(command ,students ,professors , ut_account_ptr);
            }





            cout << is_it_post_command(command) << endl;


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
    ut_account_ptr->make_post("asd" , "rjlrty");
    ut_account_ptr->make_post("qwe" , "akeshflwer");
    ut_account_ptr->make_post("zxc" , "akeshflwer");
    ut_account_ptr->show_posts();
    for(auto & s: students){
        s->add_notif(810102566 , "shayan" , "New Post");
    }
    for(auto & s: students){
        s->show_notif_vec();
    }

    deallocate(majors ,students , courses ,professors , ut_account_ptr );
    return 0;
}