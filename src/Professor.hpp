#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP
#include "global.hpp"

class Professor : public Uniperson{
public:
    void professor_csv_setup(int id_ ,string name_ , int major_id_ , string position_ , string password_){
        id = id_;
        name = name_;
        major_id = major_id_;
        position = position_;
        password = password_;
    }
    void test_show(){
        cout << "pid: " << id <<endl;
        cout << "name: " << name <<endl;
        cout << "major_id: " << major_id <<endl;
        cout << "position: " << position <<endl;
        cout << "password: " << password <<endl;
    }

    string get_position(){
        return position;
    }
private:
    string position;
};

#endif
