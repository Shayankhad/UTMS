#include "global.hpp"

bool is_it_show_course_channel_command(string command){
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
    if (iteration == 5)
    {   
        if ((commands[0] == GET) && (commands[1] == COURSE_CHANNEL) && (commands[3] == ID))
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
