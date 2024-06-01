#include "global.hpp"

int identify_user(vector<Student *> students, vector<Professor *> professors, UtAccount *ut_account_ptr)
{
    for (auto &student : students)
    {
        if (student->am_i_loged_in())
        {
            return student->get_id();
        }
    }
    for (auto &professor : professors)
    {
        if (professor->am_i_loged_in())
        {
            return professor->get_id();
        }
    }
    if (ut_account_ptr->am_i_loged_in())
    {
        return ut_account_ptr->get_id();
    }
    return -1;
}