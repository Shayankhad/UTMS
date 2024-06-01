#include "global.hpp"

void delete_post_command(string command, vector<Student *> &students, vector<Professor *> &professors, UtAccount *ut_account_ptr)
{
    int user_id = identify_user(students, professors, ut_account_ptr);
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
    int target_post_id = string_to_int(commands[4]);
    check_post_id_exist(target_post_id, students, professors, ut_account_ptr);

    for (auto &student : students)
    {
        if (student->get_id() == user_id)
        {
            student->delete_post(target_post_id);
        }
    }
    for (auto &professor : professors)
    {
        if (professor->get_id() == user_id)
        {
            professor->delete_post(target_post_id);
        }
    }
    if (ut_account_ptr->get_id() == user_id)
    {
        ut_account_ptr->delete_post(target_post_id);
    }

    throw OkExeption();
}