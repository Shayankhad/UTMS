#include "global.hpp"

bool is_it_login_command(string command)
{
    vector<string> commands = seperate_one_two_command(command);
    stringstream ss_1;
    ss_1 << command;
    string iteration_test;
    int iteration = 0;
    while (getline(ss_1, iteration_test, ' '))
    {
        if (!(iteration_test == ""))
        {
            iteration++;
        }
    }
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
    string endline_test;
    getline(ss, endline_test, '\n');
    for (char c : endline_test)
    {
        if ((c != ' '))
        {
            return false;
        }
    }
    if ((commands[0] == POST) && (commands[1] == LOGIN) && (iteration == 7))
    {
        if (((arg_1 == ID) && (arg_2 == PASSWORD)) || ((arg_2 == ID) && (arg_1 == PASSWORD)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}