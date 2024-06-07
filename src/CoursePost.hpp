#ifndef COURSEPOST_HPP
#define COURSEPOST_HPP
#include "global.hpp"
class CoursePost {
public:
    CoursePost(int presente_course_id_ , string title_ , string message_ , int post_id_){
        presente_course_id = presente_course_id_;
        title = title_;
        message = message_;
        post_id = post_id_;
    }
    
private:
    int post_id;
    int presente_course_id;
    string title;
    string message;
    string image_address;
};

#endif
