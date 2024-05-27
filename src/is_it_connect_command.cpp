#include "global.hpp"

bool is_it_connect_command(string command){
    vector<string> commands;
    stringstream ss;
    ss << command;
    string word;
    int iteration = 0 ;
    while (getline(ss, word, ' '))
    {
        commands.push_back(word);
        iteration ++;
    }
    if(iteration == 5){
        if((commands[0] == POST) && (commands[1] == CONNECT) && (commands[3] == ID)){
            return true;
        }else {
            return false;
        }
    }else {
        return false;
    }
}