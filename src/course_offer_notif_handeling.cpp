#include "global.hpp"

void course_offer_notif_handeling(vector<Student *> &students, vector<Professor *> &professors, UtAccount *ut_account_ptr, int professor_id)
{
    string professor_name;
    for (auto &professor : professors)
    {
        if (professor->get_id() == professor_id)
        {
            professor_name = professor->get_name();
        }
    }

    for (auto &student : students)
    {
        student->add_notif(professor_id, professor_name, NEW_COURSE_OFFERING);
    }
    for (auto &professor : professors)
    {
        professor->add_notif(professor_id, professor_name, NEW_COURSE_OFFERING);
    }

    ut_account_ptr->add_notif(professor_id, professor_name, NEW_COURSE_OFFERING);
}