#include "global.hpp"

int get_professor_through_presented_course_id(int presented_course_id , vector<PresentedCourse *> presented_course ){
    for(auto & p_course : presented_course){
        if(p_course->get_presented_course_id() == presented_course_id ){
            return p_course->get_professor_id();
        }
    }
    return -1;
}