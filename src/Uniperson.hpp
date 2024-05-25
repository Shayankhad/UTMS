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
    bool is_password_match(string password_){
        if(password == password_){
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
    void set_loged(login_enum x){
        is_loged_int = x;
    }
protected:
    int id;
    string name;
    int major_id;
    string password;
    login_enum is_loged_int = didnt_loged_in;
};

#endif