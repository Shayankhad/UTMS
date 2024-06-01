#include "global.hpp"

void check_take_course_time_handeling(int student_id , vector<Student *> students , int target_presented_course_id ,vector<PresentedCourse *> &presented_course ){

    Student * target_student;
    for(auto & student : students){
        if(student->get_id() == student_id){
            target_student = student;
        }
    }
    vector<int> token_courses = target_student->get_token_courses();
    PresentedCourse * each_token_course_ptr;
    PresentedCourse * target_presented_course_ptr = find_PresentedCourse(target_presented_course_id , presented_course);
    for(std::vector<int>::size_type i = 0 ; i < token_courses.size() ; i++){
        each_token_course_ptr = find_PresentedCourse(token_courses[i] , presented_course); 
        if(!each_token_course_ptr->check_student_course_timeing(target_presented_course_ptr)){
            throw PermissionDenied();
        }
    }
}