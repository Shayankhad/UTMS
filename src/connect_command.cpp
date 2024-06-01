#include "global.hpp"

void connect_command(string command, vector<Student *> &students, vector<Professor *> &professors, UtAccount *ut_account_ptr)
{
    vector<string> commands;
    stringstream ss;
    ss << command;
    string word;
    int user_id = identify_user(students, professors, ut_account_ptr);
    if (user_id == -1)
    {
        throw PermissionDenied();
    }
    while (getline(ss, word, ' '))
    {
        commands.push_back(word);
    }
    int target_id = string_to_int(commands[4]);
    if (!(check_number_type(commands[4]) == 1))
    {
        throw BadRequest();
    }
    if (!(check_id_match_in_peaple(target_id, students, professors, ut_account_ptr)))
    {
        throw NotFound();
    }

    for (auto &student : students)
    {
        if ((student->get_id() == target_id))
        {
            if (student->am_i_in_contact(user_id))
            {
                throw BadRequest();
            }
        }
        if (student->get_id() == user_id)
        {
            if (student->am_i_in_contact(target_id))
            {
                throw BadRequest();
            }
        }
    }
    for (auto &professor : professors)
    {
        if ((professor->get_id() == target_id))
        {
            if (professor->am_i_in_contact(user_id))
            {
                throw BadRequest();
            }
        }
        if (professor->get_id() == user_id)
        {
            if (professor->am_i_in_contact(target_id))
            {
                throw BadRequest();
            }
        }
    }
    if ((ut_account_ptr->get_id() == target_id))
    {
        if (ut_account_ptr->am_i_in_contact(user_id))
        {
            throw BadRequest();
        }
    }
    if (ut_account_ptr->get_id() == user_id)
    {
        if (ut_account_ptr->am_i_in_contact(target_id))
        {
            throw BadRequest();
        }
    }

    for (auto &student : students)
    {
        if ((student->get_id() == target_id))
        {
            student->add_contacts(user_id);
        }
        if (student->get_id() == user_id)
        {
            student->add_contacts(target_id);
        }
    }
    for (auto &professor : professors)
    {
        if ((professor->get_id() == target_id))
        {
            professor->add_contacts(user_id);
        }
        if (professor->get_id() == user_id)
        {
            professor->add_contacts(target_id);
        }
    }
    if ((ut_account_ptr->get_id() == target_id))
    {
        ut_account_ptr->add_contacts(user_id);
    }
    if (ut_account_ptr->get_id() == user_id)
    {
        ut_account_ptr->add_contacts(target_id);
    }
    throw OkExeption();
}