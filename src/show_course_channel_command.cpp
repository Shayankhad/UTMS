#include "global.hpp"

void show_course_channel_command(string command , int user_id ,vector<Student *> students ,vector<Professor *> professors , vector<PresentedCourse *> presented_course){
    vector<string> commands;
    stringstream ss;
    ss << command;
    string word;
    while (getline(ss, word, ' '))
    {
        if (!(word == ""))
        {
            commands.push_back(word);
        }
    }
    if (user_id == 0){
        throw PermissionDenied();
    }
    int presented_course_id = string_to_int(commands[4]);
    vector <int> all_courses;
    all_courses = get_all_presented_courses(professors);
    bool does_id_exist = false;
    bool does_id_has_per = false;

    for(auto & student : students){
        if(student->get_id() == user_id){
            for(auto & x : all_courses){
                if(x == presented_course_id){
                    does_id_exist = true;
                }
            }
            vector<int> tooken_course;
            tooken_course = student->get_token_courses();
            for(auto & a : tooken_course){
                if(a == presented_course_id){
                    does_id_has_per = true;
                }
            }
        }
    }

    for(auto & professor : professors){
        if(professor->get_id() == user_id){
            for(auto & x : all_courses){
                if(x == presented_course_id){
                    does_id_exist = true;
                }
            }
            vector<int> tooken_course;
            tooken_course = professor->get_token_courses();
            for(auto & a : tooken_course){
                if(a == presented_course_id){
                    does_id_has_per = true;
                }
            }
        }
    }

    if(!does_id_exist){
        throw NotFound();
    }

    if(!does_id_has_per){
        throw PermissionDenied();
    }    

    for(auto & p_course : presented_course){
        if(p_course->get_presented_course_id() == presented_course_id){
            p_course->show_summery_post_courses();
        }
    }
}
