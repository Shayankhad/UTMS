#ifndef COURSEPOST_HPP
#define COURSEPOST_HPP
#include "global.hpp"
class CoursePost {
public:
    CoursePost(int who_made_  , string who_made_name_, int presente_course_id_ , string presented_course_name_ , string title_ , string message_ , int post_id_){
        who_made = who_made_;
        who_made_name = who_made_name_;
        presente_course_id = presente_course_id_;
        presente_course_name = presented_course_name_;
        title = title_;
        message = message_;
        post_id = post_id_;
    }
    CoursePost(int who_made_  , string who_made_name_, int presente_course_id_ , string presented_course_name_ , string title_ , string message_ , int post_id_ , string image_address_){
        who_made = who_made_;
        who_made_name = who_made_name_;
        presente_course_id = presente_course_id_;
        presente_course_name = presented_course_name_;
        title = title_;
        message = message_;
        post_id = post_id_;
        image_address = image_address_;
    }
    void show_image(){
        cout << image_address << endl;
    }
    void show_type_one(){
        cout << post_id << " " << who_made_name << " " << '"' << title << '"' << endl; 
    }
private:
    int who_made;
    string who_made_name;
    int post_id;
    int presente_course_id;
    string presente_course_name;
    string title;
    string message;
    string image_address;
};

#endif
