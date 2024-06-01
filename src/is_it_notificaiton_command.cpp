#include "global.hpp"

bool is_it_notificaiton_command(string command)
{
    vector<string> commands;
    stringstream ss;
    ss << command;
    string word;
    int iteration = 0;
    while (getline(ss, word, ' '))
    {
        if (!(word == ""))
        {
            commands.push_back(word);
            iteration++;
        }
    }
    if (iteration == 3)
    {
        if ((commands[0] == GET) && (commands[1] == NOTIFICATION) && (commands[2] == "?"))
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