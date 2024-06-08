#include "global.hpp"

void show_course_post_command(int user_id , string command , vector<PresentedCourse *> presented_course , vector<Student *> students , vector<Professor *> professors){
    vector<string> commands;
    stringstream ss;
    ss << command;
    string word;
    int iteration = 0;
    while (getline(ss, word, ' '))
    {
        if (!(word == ""))
        {
            commands.push_back(word);
            iteration++;
        }
    }
    vector<vector<string>> command_args;
    command_args.push_back({commands[3] , commands[4]});
    command_args.push_back({commands[5] , commands[6]});
    command_args = sort_show_course_post_args(command_args);

    if(check_number_type(command_args[0][1]) != 1){
        throw BadRequest();
    }
    int id = string_to_int(command_args[0][1]);
    if(check_number_type(command_args[1][1]) != 1){
        throw BadRequest();
    }
    int post_id = string_to_int(command_args[1][1]);

    if(!is_presented_course_id_exist(presented_course , id)){
        throw NotFound();
    }
    PresentedCourse * presented_course_ptr = find_PresentedCourse(id , presented_course); 
    if(!presented_course_ptr->does_post_exist(post_id)){
        throw NotFound();
    }

    bool does_id_has_per = false;

    for(auto & student : students){
        if(student->get_id() == user_id){
            vector<int> tooken_course;
            tooken_course = student->get_token_courses();
            for(auto & a : tooken_course){
                if(a == id){
                    does_id_has_per = true;
                }
            }
        }
    }

    for(auto & professor : professors){
        if(professor->get_id() == user_id){
            vector<int> tooken_course;
            tooken_course = professor->get_token_courses();
            for(auto & a : tooken_course){
                if(a == id){
                    does_id_has_per = true;
                }
            }
        }
    }
    if(!does_id_has_per){
        throw PermissionDenied();
    }   

    presented_course_ptr->show_specific_post(post_id);
}
