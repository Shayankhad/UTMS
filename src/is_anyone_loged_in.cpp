#include "global.hpp"


bool is_anyone_loged_in(vector<Student *> students, vector<Professor *> professors, UtAccount *ut_account_ptr)
{
    bool result = false;
    for (auto &student : students)
    {
        if (student->am_i_loged_in())
        {
            result = true;
        }
    }
    for (auto &professor : professors)
    {
        if (professor->am_i_loged_in())
        {
            result = true;
        }
    }
    if (ut_account_ptr->am_i_loged_in())
    {
        result = true;
    }
    return result;
}
