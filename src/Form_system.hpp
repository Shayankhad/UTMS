#ifndef FORM_SYSTEM_HPP
#define FORM_SYSTEM_HPP
#include "global.hpp"

class Form_system
{
public:
private:
    int form_id;
    int presented_course_id;
    string message;
    vector<Student *> registered_students;
};

#endif