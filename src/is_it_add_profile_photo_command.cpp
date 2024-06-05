#include "global.hpp"


bool is_it_add_profile_photo_command(string command){
    vector<string> commands;
    string word;
    stringstream ss;
    ss << command;
    int iteration = 0;
    while (getline(ss, word, ' '))
    {
        if (!word.empty())
        {
            commands.push_back(word);
            iteration++;
        }
    }

    if (iteration == 5)
    {
        if ((commands[0] == POST) && (commands[1] == PROFILE_PHOTO) && (commands[2] == QUESTION_MARK) && (commands[3] == PHOTO))
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