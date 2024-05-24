#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "global.hpp"

class Student : public Uniperson  {
public:
    void student_csv_setup(int id_ ,string name_ , int major_id_ , int semester_ , string password_){
        id = id_;
        name = name_;
        major_id = major_id_;
        semester = semester_;
        password = password_;
    }
private:
    int semester;
};

#endif
