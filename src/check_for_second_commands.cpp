#include "global.hpp"

void check_for_second_commands(string command)
{
    stringstream ss;
    ss << command;
    string word;
    getline(ss, word, ' ');
    getline(ss, word, ' ');
    if (!((word == LOGIN) || (word == LOGOUT) || (word == COURSES) || (word == POST_SECOND_COMMAND) ||
          (word == PERSONAL_PAGE) || (word == CONNECT) || (word == NOTIFICATION) ||
          (word == COURSE_OFFER) || (word == MY_COURSES) || (word == PROFILE_PHOTO)))
    {
        throw NotFound();
    }
}
