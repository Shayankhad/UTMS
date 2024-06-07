#include "global.hpp"

void make_course_post_command_type_two(int user_id,string command , vector<Student *> &students , vector<Professor *> &professors , vector<PresentedCourse *> &presented_course ){
    string arg_sample;
    string arg_sample_val;
    string space_sample_val;
    stringstream ss;
    ss << command;
    getline(ss , space_sample_val , ' ');
    getline(ss , space_sample_val , ' ');
    getline(ss , space_sample_val , ' ');
    vector<vector<string>> commands(4);
    for(int i = 0 ; i < 4 ; i++){
        getline(ss , arg_sample , ' ');
        if((arg_sample != ID) && (arg_sample != IMAGE)){
            getline(ss, arg_sample_val , '"');
            getline(ss, arg_sample_val , '"');
            getline(ss, space_sample_val , ' ');
        }else{
            getline(ss , arg_sample_val , ' ' );
        }
        commands[i]= {arg_sample , arg_sample_val};
    }
    commands = sort_course_post_type_two_command(commands); 
    if (user_id == 0){
        throw PermissionDenied();
    }
    int presnted_course_id = string_to_int(commands[0][1]);
    string post_title = commands[1][1];
    string post_message = commands[2][1];
    string post_image = commands[3][1];
    string author_name;
    vector <int> all_courses;
    all_courses = get_all_presented_courses(professors);
    bool does_id_exist = false;
    bool does_id_has_per = false;

    for(auto & student : students){
        if(student->get_id() == user_id){
            author_name = student->get_name();
            for(auto & x : all_courses){
                if(x == presnted_course_id){
                    does_id_exist = true;
                }
            }
            vector<int> tooken_course;
            tooken_course = student->get_token_courses();
            for(auto & a : tooken_course){
                if(a == presnted_course_id){
                    does_id_has_per = true;
                }
            }
        }
    }

    for(auto & professor : professors){
        if(professor->get_id() == user_id){
            author_name = professor->get_name();
            for(auto & x : all_courses){
                if(x == presnted_course_id){
                    does_id_exist = true;
                }
            }
            vector<int> tooken_course;
            tooken_course = professor->get_token_courses();
            for(auto & a : tooken_course){
                if(a == presnted_course_id){
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

    PresentedCourse * presented_course_ptr = find_PresentedCourse(presnted_course_id , presented_course);
    string presented_course_name = presented_course_ptr->get_course_name();
    presented_course_ptr->add_course_post_with_image(user_id , author_name , presnted_course_id , presented_course_name , post_title , post_message , post_image);
    post_course_notif_handle(user_id , presnted_course_id , presented_course_name , students , professors);
    throw OkExeption();
}
