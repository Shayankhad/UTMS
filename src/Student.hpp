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
    void test_show(){
        cout << "sid: " << id << endl;
        cout << "name: "<< name << endl;
        cout << "major_id: "<< major_id << endl;
        cout << "semester: "<< semester << endl;
        cout << "password: "<< password << endl;
    }

    int get_semester(){
        return semester;
    }
private:
    int semester;
};

#endif
