#ifndef NOTIF_HPP
#define NOTIF_HPP
#include "global.hpp"
class Notif{
private:
    Notif(int id_ , string name_ , string notif_type_){
        id = id_;
        name = name_;
        notif_type = notif_type_;
    }
    void show_notif(){
        cout << id << " " << name << ":" << " " << notif_type << endl;
    }
public:
    int id;
    string name;
    string notif_type;
};

#endif

