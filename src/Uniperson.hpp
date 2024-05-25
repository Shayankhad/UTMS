#ifndef UNIPERSON_HPP
#define UNIPERSON_HPP
#include "global.hpp"

class Uniperson {
public:
    Uniperson(){
    }

    bool is_id_match(int id_){
        if(id == id_){
            return true;
        }else{
            return false;
        }
    }
    bool is_id_password(int password_){
        if(id == password_){
            return true;
        }else{
            return false;
        }
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