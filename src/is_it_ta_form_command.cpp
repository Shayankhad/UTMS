#include "global.hpp"

bool is_it_ta_form_command(string command){
    string help_str;
    stringstream ss;
    ss << command;
    string command_1;
    getline(ss , command_1 , ' ');
    string command_2;
    getline(ss , command_2 , ' ');
    string q_mark;
    getline(ss , q_mark , ' ');
    if((command_1 != POST) || (command_2 != TA_FORM) || (q_mark != QUESTION_MARK)){
        return false;
    }
    vector<char> command_char;

    string arg_sample;
    string arg_sample_val;
    string space_sample_val;
    vector<vector<string>> commands(2);
    for(int i = 0 ; i < 2 ; i++){
        getline(ss , arg_sample , ' ');
        if(arg_sample.empty()){
            return false;
        }
        if(arg_sample != COURSE_ID){
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

    for(std::__cxx11::basic_string<char>::size_type i = 0 ; i < command.size() ; i++ ){
        if(!(command[i] == ' ')){
            command_char.push_back(command[i]);
        }
    }
    if(commands[1][0] != COURSE_ID){
        if(!(command_char[command_char.size() - 1] == '"')){
            return false;
        }
    }


    if(!check_ta_form_args(commands)){
        return false;
    }
    return true;
}