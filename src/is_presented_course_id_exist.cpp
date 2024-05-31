#include "global.hpp"


bool is_presented_course_id_exist(vector<PresentedCourse *> presented_course , int target_presented_course_id){
    for(auto & presented_c : presented_course){
        if(presented_c->get_presented_course_id() == target_presented_course_id){
            return true;
        }
    }
    return false;
}