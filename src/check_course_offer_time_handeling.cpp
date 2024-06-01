#include "global.hpp"

void check_course_offer_time_handeling(vector<PresentedCourse *> presented_course, vector<int> hour, string day, int proffesor_id)
{
    for (auto &presented_course : presented_course)
    {
        if (!presented_course->check_start_and_finish_time_class_interference(hour, day, proffesor_id))
        {
            throw PermissionDenied();
        }
    }
}