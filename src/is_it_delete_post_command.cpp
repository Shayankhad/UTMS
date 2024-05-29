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