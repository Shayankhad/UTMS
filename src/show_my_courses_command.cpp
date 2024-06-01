#include "global.hpp"

void show_my_courses_command(int student_id , vector<Student *> students ,vector<PresentedCourse *> presented_course ){
    vector<int> token_courses;
    for(auto & student: students){
        if(student->get_id() == student_id){
            token_courses = student->get_token_courses();
        }
    }
    if(token_courses.size() == 0){
        throw Empty();
    }
    PresentedCourse * current_presented_course;
    for(std::vector<int>::size_type i = 0 ; i < token_courses.size() ; i++){
        current_presented_course = find_PresentedCourse(token_courses[i] , presented_course);
        current_presented_course->show_type_2();
    }
}