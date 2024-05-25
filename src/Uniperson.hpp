#ifndef UNIPERSON_HPP
#define UNIPERSON_HPP
#include "global.hpp"

class Uniperson {
public:
    Uniperson(){
    }
    bool check_login(int id_ , string password_){

    }
    login_enum am_i_loged_in(){
        return is_loged_int;
    }
    int get_id(){
        return id;
    }
protected:
    int id;
    string name;
    int major_id;
    string password;
    login_enum is_loged_int = didnt_loged_in;
};

#endif