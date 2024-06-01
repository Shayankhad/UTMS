#include "global.hpp"

bool is_it_logout_command(string command)
{
    vector<string> commands = seperate_one_two_command(command);
    stringstream ss;
    ss << command;
    string word;
    int iteration = 0;
    while (getline(ss, word, ' '))
    {
        if (!(word == ""))
        {
            iteration++;
        }
    }
    if (iteration == 3)
    {
        if ((commands[0] == POST) && (commands[1] == LOGOUT))
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