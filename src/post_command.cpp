#include "global.hpp"


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
        post_command_setup(user_id , arg_1_value , arg_2_value , students ,professors , ut_account_ptr );
        throw OkExeption();
    }
    
    else if((arg_1 == MESSAGE) && (arg_2 == TITLE)){
        post_command_setup(user_id ,  arg_2_value , arg_1_value, students ,professors , ut_account_ptr );
        throw OkExeption();
    }
}