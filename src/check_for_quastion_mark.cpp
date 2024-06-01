#include "global.hpp"

void check_for_quastion_mark(string command)
{
    stringstream ss;
    ss << command;
    string word;
    getline(ss, word, ' ');
    getline(ss, word, ' ');
    getline(ss, word, ' ');
    if (!(word == "?"))
    {
        throw BadRequest();
    }
}