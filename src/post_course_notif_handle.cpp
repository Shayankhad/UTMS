#include "global.hpp"

void post_course_notif_handle(int user_id , int presented_course_id , string presented_course_name, vector<Student *> &students , vector<Professor *> &professors){
    for(auto &student : students){
        for(auto & int_courses : student->get_token_courses()){
            if(int_courses == presented_course_id){
                if(student->get_id() != user_id){
                    student->add_notif(presented_course_id , presented_course_name , NEW_COURSE_POST);
                }
            }
        }
    }

    for(auto & professor : professors){
        for(auto & int_courses : professor->get_token_courses()){
            if(int_courses == presented_course_id){
                if(professor->get_id() != user_id){
                    professor->add_notif(presented_course_id , presented_course_name , NEW_COURSE_POST);
                }
            }
        }
    }
}