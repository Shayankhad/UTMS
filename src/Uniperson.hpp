#ifndef UNIPERSON_HPP
#define UNIPERSON_HPP
#include "global.hpp"

class Uniperson {
public:
    Uniperson(){
    }
    void check_login(int id_ , string password_){
        if((id == id_) && (password == password_)){
            is_loged_int = loged_in;
        }
    }
    login_enum am_i_loged_in(){
        return is_loged_int;
    }
protected:
    int id;
    string name;
    int major_id;
    string password;
    login_enum is_loged_int = didnt_loged_in;
};

#endif