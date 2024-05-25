#include "global.hpp"


bool is_it_login_command(string command)
{
    vector<string> commands = seperate_one_two_command(command);
    stringstream ss;
    ss << command;
    string word;
    getline(ss, word, '?');
    getline(ss, word, ' ');
    getline(ss, word, ' ');
    string arg_1 = word;
    getline(ss, word, ' ');
    string arg_1_value = word;
    getline(ss, word, ' ');
    string arg_2 = word;
    getline(ss, word, ' ');
    string arg_2_value = word;
    if ((commands[0] == POST) && (commands[1] == LOGIN))
    {
        if(((arg_1 == ID) && (arg_2 == PASSWORD)) || ((arg_2 == ID) && (arg_1 == PASSWORD))){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}