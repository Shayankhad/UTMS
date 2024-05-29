#include "global.hpp"


bool is_it_post_command(string command){
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