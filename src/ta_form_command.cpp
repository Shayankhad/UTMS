#include "global.hpp"

void ta_form_command(string command , int user_id , vector<Student *> &students , vector<Professor *> &professors , UtAccount *ut_account_ptr , vector<PresentedCourse *> &presented_course){
    string arg_sample;
    string arg_sample_val;
    string space_sample_val;
    vector<vector<string>> commands(2);
    stringstream ss;
    ss << command;
    getline(ss , space_sample_val , ' ');
    getline(ss , space_sample_val , ' ');
    getline(ss , space_sample_val , ' ');
    for(int i = 0 ; i < 2 ; i++){
        getline(ss , arg_sample , ' ');
        if(arg_sample != COURSE_ID){
            getline(ss, arg_sample_val , '"');
            getline(ss, arg_sample_val , '"');
            getline(ss, space_sample_val , ' ');
        }else{
            getline(ss , arg_sample_val , ' ' );
        }
        commands[i]= {arg_sample , arg_sample_val};
    }
    commands = sort_ta_form_args(commands);
    if(check_number_type(commands[0][1]) != 1){
        throw BadRequest();
    }
    int presented_course_id = string_to_int(commands[0][1]);
    if(presented_course_id <=0){
        throw BadRequest();
    }
    string message = commands[1][1];
    if(!is_presented_course_id_exist(presented_course , presented_course_id)){
        throw NotFound();
    }
    if(!is_it_professor(user_id , professors)){
        throw PermissionDenied();
    }
    bool does_id_has_per = false;
    for(auto & professor : professors){
        if(professor->get_id() == user_id){
            vector<int> tooken_course;
            tooken_course = professor->get_token_courses();
            for(auto & a : tooken_course){
                if(a == presented_course_id){
                    does_id_has_per = true;
                }
            }
        }
    }
    if(!does_id_has_per){
        throw PermissionDenied();
    }  

    int professor_id = get_professor_through_presented_course_id(presented_course_id , presented_course);
    string presented_course_name;
    for(auto & p_course : presented_course){
        if(p_course->get_presented_course_id() == presented_course_id){
            presented_course_name = p_course->get_course_name();
        }
    }
    
    for(auto & professor : professors){
        if(professor->get_id() == professor_id){
            professor->make_form(message , presented_course_id , presented_course_name);
        }
    }

    add_notif_handeling(students , professors  , ut_account_ptr  , NEW_FORM , user_id);

    throw OkExeption(); 

}