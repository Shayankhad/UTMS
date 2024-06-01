#include "global.hpp"

void show_presented_course_type_two_command(string command, vector<PresentedCourse *> presented_course)
{
    vector<string> commands;
    string word;
    stringstream ss;
    ss << command;
    while (getline(ss, word, ' '))
    {
        if (!word.empty())
        {
            commands.push_back(word);
        }
    }

    if ((check_number_type(commands[4]) != 1))
    {
        throw BadRequest();
    }
    if (string_to_int(commands[4]) <= 0)
    {
        throw BadRequest();
    }
    int target_presented_course_id = string_to_int(commands[4]);

    if (!is_presented_course_id_exist(presented_course, target_presented_course_id))
    {
        throw NotFound();
    }

    for (auto &presented_c : presented_course)
    {
        if (target_presented_course_id == presented_c->get_presented_course_id())
        {
            presented_c->show_type_2();
        }
    }
}
