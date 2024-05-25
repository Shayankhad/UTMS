#include "global.hpp"

vector<string> seperate_one_two_command(string command)
{
    stringstream ss;
    ss << command;
    string word;
    vector<string> commands;
    getline(ss, word, ' ');
    commands.push_back(word);
    getline(ss, word, ' ');
    commands.push_back(word);
    return commands;
}