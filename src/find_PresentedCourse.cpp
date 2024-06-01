#include "global.hpp"

PresentedCourse *find_PresentedCourse(int presented_course_id, vector<PresentedCourse *> presented_course)
{
    for (auto &presented_c : presented_course)
    {
        if (presented_c->get_presented_course_id() == presented_course_id)
        {
            return presented_c;
        }
    }
    return nullptr;
}