#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "global.hpp"

class Student {
public:
    void x(){
        cout << PERMISSION_DENIED ;
    }
private:
    int sid;
    string name;
    int major_id;
    int semester;
    string password;
    login_enum is_loged_in = didnt_loged_in;
};

#endif
