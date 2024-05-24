#ifndef UNIPERSON_HPP
#define UNIPERSON_HPP
#include "global.hpp"

class Uniperson {
public:
    Uniperson(){
    }
protected:
    int id;
    string name;
    int major_id;
    string password;
    login_enum is_loged_int = didnt_loged_in;
};

#endif