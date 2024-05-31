#include "global.hpp"

bool is_it_show_presented_course_type_two_command(string command){
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
        if((commands[0] == GET ) && (commands[1] == COURSES) && (commands[2] == QUESTION_MARK) && (commands[3] == ID)){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}