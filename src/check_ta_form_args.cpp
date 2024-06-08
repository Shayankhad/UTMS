#include "global.hpp"

bool check_ta_form_args(vector<vector<string>> commands){
    bool does_it_have_course_id = false;
    for(auto & layer_1 : commands){
        if(layer_1[0] == COURSE_ID){
            does_it_have_course_id = true;
        }
    }
    bool does_it_have_message = false;
    for(auto & layer_1 : commands){
        if(layer_1[0] == MESSAGE){
            does_it_have_message = true;
        }
    }
    return (does_it_have_course_id && does_it_have_message);
}