#ifndef FORMSYSTEM_HPP
#define FORMSYSTEM_HPP
#include "global.hpp"

class FormSystem
{
public:
    FormSystem(int form_id_  , int presented_course_id_ ,string presented_course_name_ , string message_ ,  int author_id_ , string author_name_ ){
        form_id = form_id_;
        presented_course_id = presented_course_id_;
        presented_course_name = presented_course_name_;
        message = message_;
        author_id = author_id_;
        author_name = author_name_;
    }
    void show_title_of_forms(){
        cout << form_id << ' ' << TA_FORM_FOR << ' ' <<  presented_course_name << ' ' << COURSE << endl;
    }
    int get_form_id(){
        return form_id;
    }
private:
    int form_id;
    int presented_course_id;
    string presented_course_name;
    string message;
    int author_id;
    string author_name;
};

#endif