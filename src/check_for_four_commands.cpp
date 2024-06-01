#include "global.hpp"

void check_for_four_commands(string command)
{
    stringstream ss;
    ss << command;
    string word;
    getline(ss, word, ' ');
    if (!((word == GET) || (word == POST) || (word == DELETE) || (word == PUT)))
    {
        throw BadRequest();
    }
}
