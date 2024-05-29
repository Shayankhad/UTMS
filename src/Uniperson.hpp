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
        for (vector<int>::size_type i = 0 ; i < contacts.size() ; i++){
            cout << contacts[i] << endl;
        }
    }

    bool am_i_in_contact(int contact_id){
        for(vector<int>::size_type i = 0 ; i < contacts.size() ; i ++){
            if(contacts[i] == contact_id){
                return true;
            }
        }
        return false;
    }
    void make_post(string post_title , string post_message){
        Post_system * new_post;
        new_post = new Post_system(post_id , post_title ,post_message);
        posts_i_made.emplace_back(new_post);
        post_id ++;
    }
    void show_posts(){
        for(auto &x : posts_i_made){
            x->show_full_post_system();
        }
    }
    
    void add_notif(int notif_id , string notif_name , string notif_type_){
        Notif * notif_ptr;
        notif_ptr = new Notif(notif_id , notif_name , notif_type_);
        notifications.emplace_back(notif_ptr);
    }

    void show_notif_vec(){
        for(auto & x : notifications){
            x->show_notif();
        }
    }

    void deallocate_uniperson(){
        for (Post_system *x : posts_i_made)
        {
            delete x;
        }
        posts_i_made.clear();
        for (Notif*x : notifications)
        {
            delete x;
        }
        notifications.clear();  
    }
protected:
    int id;
    string name;
    int major_id;
    string password;
    int is_loged_int = 0;
    vector<int> contacts;
    vector<Post_system *> posts_i_made;
    int post_id = 1 ;
    vector<Notif*> notifications;
};

#endif