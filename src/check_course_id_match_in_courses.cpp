#include "global.hpp"

bool check_course_id_match_in_courses(int course_id, vector<Course *> courses)
{
    for (auto &course : courses)
    {
        if (course->get_id() == course_id)
        {
            return true;
        }
    }
    return false;
}