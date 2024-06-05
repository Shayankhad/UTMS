#include "global.hpp"


void post_image_command(int user_id , string command , vector<Student *> &students, vector<Professor *> &professors, UtAccount *ut_account_ptr){
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
    if((command_1 == POST) && (command_2 == POST_SECOND_COMMAND) && (q_mark == QUESTION_MARK)){
        for(auto & s : students){
            if(s->get_id() == user_id){
                s->make_post_with_image(args[0][1] ,args[1][1] , args[2][1] );
                add_notif_handeling(students , professors , ut_account_ptr , NEW_POST , user_id);
            }
        }
        for(auto & p : professors){
            if(p->get_id() == user_id){
                p->make_post_with_image(args[0][1] ,args[1][1] , args[2][1] );
                add_notif_handeling(students , professors , ut_account_ptr , NEW_POST , user_id);
            }
        }
        if(ut_account_ptr->get_id() == user_id){
            ut_account_ptr->make_post_with_image(args[0][1] ,args[1][1] , args[2][1] );
            add_notif_handeling(students , professors , ut_account_ptr , NEW_POST , user_id);
        }
    }
    throw OkExeption();
}