#include "global.hpp"

void login_setup(string arg_1_value, string arg_2_value, vector<Student *> &students, vector<Professor *> &professors, UtAccount *ut_account_ptr)
{
    for (auto &student : students)
    {
        if (student->is_id_match(string_to_int(arg_1_value)))
        {
            if (student->is_password_match(arg_2_value))
            {
                student->set_loged(1);
                throw OkExeption();
            }
            else
            {
                throw PermissionDenied();
            }
        }
    }
    for (auto &professor : professors)
    {
        if (professor->is_id_match(string_to_int(arg_1_value)))
        {
            if (professor->is_password_match(arg_2_value))
            {
                professor->set_loged(1);
                throw OkExeption();
            }
            else
            {
                throw PermissionDenied();
            }
        }
    }
    if (ut_account_ptr->is_id_match(string_to_int(arg_1_value)))
    {
        if (ut_account_ptr->is_password_match(arg_2_value))
        {
            ut_account_ptr->set_loged(1);
            throw OkExeption();
        }
        else
        {
            throw PermissionDenied();
        }
    }
    throw NotFound();
}