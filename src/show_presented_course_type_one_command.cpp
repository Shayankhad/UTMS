#include "global.hpp"

void show_presented_course_type_one_command(vector<PresentedCourse *> presented_course)
{
    if (how_many_courses_presented(presented_course) == 0)
    {
        throw Empty();
    }
    for (auto &presented_c : presented_course)
    {
        presented_c->show_type_1();
    }
}