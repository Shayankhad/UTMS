#include "global.hpp"

bool is_it_show_course_post_command(string command){
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
    if (iteration == 7)
    {
        if (((commands[0] == GET) && (commands[1] == COURSE_POST) && (commands[2] == "?") && (commands[3] == ID) && (commands[5] == POST_ID)) || ((commands[0] == GET) && (commands[1] == COURSE_POST) && (commands[2] == "?") && (commands[3] == POST_ID) && (commands[5] == ID)))
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