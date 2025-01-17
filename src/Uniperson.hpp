#ifndef UNIPERSON_HPP
#define UNIPERSON_HPP
#include "global.hpp"

class Uniperson
{
public:
    Uniperson()
    {
    }

    bool is_id_match(int id_)
    {
        if (id == id_)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool is_password_match(string password_)
    {
        if (password == password_)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int am_i_loged_in()
    {
        return is_loged_int;
    }
    int get_id()
    {
        return id;
    }

    string get_name()
    {
        return name;
    }
    void set_loged(int x)
    {
        is_loged_int = x;
    }
    void add_contacts(int id_)
    {
        contacts.push_back(id_);
    }

    void show_contacts()
    {
        for (vector<int>::size_type i = 0; i < contacts.size(); i++)
        {
            cout << contacts[i] << endl;
        }
    }

    bool am_i_in_contact(int contact_id)
    {
        for (vector<int>::size_type i = 0; i < contacts.size(); i++)
        {
            if (contacts[i] == contact_id)
            {
                return true;
            }
        }
        return false;
    }
    void make_post(string post_title, string post_message)
    {
        Post_system *new_post;
        new_post = new Post_system(post_id, post_title, post_message);
        posts_i_made.emplace_back(new_post);
        post_id++;
    }
    void make_post_with_image(string post_title, string post_message , string image_address)
    {
        Post_system *new_post;
        new_post = new Post_system(post_id, post_title, post_message , image_address);
        posts_i_made.emplace_back(new_post);
        post_id++;
    }
    bool is_post_id_match(int post_id_)
    {
        for (auto &post_element : posts_i_made)
        {
            if (post_element->get_post_id() == post_id_)
            {
                return true;
            }
        }
        return false;
    }

    bool is_form_id_match(int form_id_)
    {
        for (auto &form_element : forms_i_made)
        {
            if (form_element->get_form_id() == form_id_)
            {
                return true;
            }
        }
        return false;
    }

    void delete_post(int target_post_id)
    {
        for (std::vector<Post_system *>::size_type i = 0; i < posts_i_made.size(); i++)
        {
            if ((posts_i_made[i]->get_post_id()) == target_post_id)
            {
                posts_i_made.erase(posts_i_made.begin() + i);
            }
        }
    }

    void show_title_of_my_posts()
    {
        for(int i = post_id - 1 ; i > 0 ; i -- ){
            if(is_post_id_match(i)){
                for(auto & target_post : posts_i_made){
                    if(target_post->get_post_id() == i){
                        target_post->show_title_post_system();
                    }
                }
            }
            if(is_form_id_match(i)){
                for(auto & target_form : forms_i_made){
                    if(target_form->get_form_id() == i){
                        target_form->show_title_of_forms();
                    }
                }
            }
        }
    }
    void show_my_posts()
    {
        for (auto &x : posts_i_made)
        {
            x->show_full_post_system();
        }
    }
    void show_specific_posts(int post_id_)
    {
        for (auto &x : posts_i_made)
        {
            if (x->get_post_id() == post_id_)
            {
                x->show_full_post_system();
            }
        }
    }

    void add_notif(int notif_id, string notif_name, string notif_type_)
    {
        Notif *notif_ptr;
        notif_ptr = new Notif(notif_id, notif_name, notif_type_);
        notifications.emplace_back(notif_ptr);
    }
    bool is_notifications_empty()
    {
        if ((notifications.size() == 0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void show_notif_vec()
    {
        for (auto notif_element = notifications.rbegin(); notif_element != notifications.rend(); ++notif_element)
        {
            (*notif_element)->show_notif();
        }
        for (Notif *notif_element : notifications)
        {
            delete notif_element;
        }
        notifications.clear();
    }


    int get_major_id()
    {
        return major_id;
    }

    void add_token_courses(int id_)
    {
        token_courses.push_back(id_);
    }

    void show_token_courses()
    {
        for (vector<int>::size_type i = 0; i < token_courses.size(); i++)
        {
            cout << name << ": " << token_courses[i] << endl;
        }
    }

    vector<int> get_token_courses()
    {
        return token_courses;
    }
    void add_profile_photo(string photo_address_){
        profile_photo = photo_address_;
    }

    void show_profile_photo(){
        cout << profile_photo << endl;
    }

    void make_form(string message , int presented_course_id_ , string presented_course_name_ )
    {
        FormSystem *new_form;
        new_form = new FormSystem(post_id , presented_course_id_ , presented_course_name_ , message , id , name );
        forms_i_made.emplace_back(new_form);
        post_id++;
    }

    void deallocate_uniperson()
    {
        for (Post_system *x : posts_i_made)
        {
            delete x;
        }
        posts_i_made.clear();
        for (Notif *x : notifications)
        {
            delete x;
        }
        notifications.clear();
        for (FormSystem *x : forms_i_made)
        {
            delete x;
        }
        forms_i_made.clear();
    }
    
protected:
    int id;
    string name;
    int major_id;
    string password;
    int is_loged_int = 0;
    vector<int> contacts;
    vector<Post_system *> posts_i_made;
    int post_id = 1;
    vector<Notif *> notifications;
    vector<int> token_courses;
    string profile_photo;
    vector<FormSystem *> forms_i_made;
};

#endif