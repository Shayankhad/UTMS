#include "global.hpp"


void login_command(string command, vector<Student *> &students, vector<Professor *> &professors, UtAccount *ut_account_ptr)
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
        if(!(((arg_1 == ID) && (arg_2 == PASSWORD)) || ((arg_2 == ID) && (arg_1 == PASSWORD)))){
            throw BadRequest();
        }
        else if((arg_1 == ID) && (arg_2 == PASSWORD)){
            login_setup(arg_1_value , arg_2_value ,students,professors,ut_account_ptr);
        }
        else if((arg_2 == ID) && (arg_1 == PASSWORD)){
            login_setup(arg_2_value , arg_1_value ,students,professors,ut_account_ptr);
        }
    }
}