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

    int am_i_loged_in(){
        return is_loged_int;
    }
    int get_id(){
        return id;
    }
    void set_loged(int x){
        is_loged_int = x;
    }
    void add_contacts(int id_){
        contacts.push_back(id_);
    }

    void show_contacts(){
        for (std::vector<int>::size_type i = 0 ; i < contacts.size() ; i++){
            cout << contacts[i] << endl;
        }
    }
protected:
    int id;
    string name;
    int major_id;
    string password;
    int is_loged_int = 0;
    vector<int> contacts;
    vector<vector<string>> notifications; // title & message
    vector<vector<string>> i_posted;
};

#endif