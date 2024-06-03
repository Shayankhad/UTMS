#ifndef POST_SYSTEM_HPP
#define POST_SYSTEM_HPP
#include "global.hpp"

class Post_system
{
public:
    Post_system(int id_, string title_, string message_)
    {
        id = id_;
        title = title_;
        message = message_;
    }
    void show_full_post_system()
    {
        cout << id << " " << '"' << title << '"' << " " << '"' << message << '"' << endl;
    }
    void show_title_post_system()
    {
        cout << id << " " << '"' << title << '"' << endl;
    }

    int get_post_id()
    {
        return id;
    }

private:
    int id;
    string title;
    string message;
    string image_address;
};

#endif