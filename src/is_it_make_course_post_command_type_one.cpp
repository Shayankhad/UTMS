#include "global.hpp"

bool is_it_make_course_post_command_type_one(string command){
    
    string help_str;
    stringstream ss;
    ss << command;
    string command_1;
    getline(ss , command_1 , ' ');
    string command_2;
    getline(ss , command_2 , ' ');
    string q_mark;
    getline(ss , q_mark , ' ');
    if((command_1 != POST) || (command_2 != COURSE_POST ) || (q_mark != QUESTION_MARK)){
        return false;
    }
    vector<char> command_char;
    for(std::__cxx11::basic_string<char>::size_type i = 0 ; i < command.size() ; i++ ){
        if(!(command[i] == ' ')){
            command_char.push_back(command[i]);
        }
    }
    string arg_sample;
    string arg_sample_val;
    string space_sample_val;
    vector<vector<string>> commands(3);
    for(int i = 0 ; i < 3 ; i++){
        getline(ss , arg_sample , ' ');
        if(arg_sample.empty()){
            return false;
        }
        if(arg_sample != ID){
            getline(ss, arg_sample_val , '"');
            getline(ss, arg_sample_val , '"');
            getline(ss, space_sample_val , ' ');
        }else{
            getline(ss , arg_sample_val , ' ' );
        }
        if(arg_sample.empty()){
            return false;
        }
        if(arg_sample_val.empty()){
            return false;
        }
        commands[i]= {arg_sample , arg_sample_val};
    }
    while(getline(ss , space_sample_val , ' ')){
        if((space_sample_val != " ") && (space_sample_val != "") ){
            return false;
        }
    }

    if(commands[2][0] != ID){
        if(!(command_char[command_char.size() - 1] == '"')){
            return false;
        }
    }

    if(!check_make_course_post_type_one_args(commands)){
        return false;
    }
    return true;
}