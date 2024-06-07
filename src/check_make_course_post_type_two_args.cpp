#include "global.hpp"

bool check_make_course_post_type_two_args(vector<vector<string>> commands){
    bool does_it_have_id = false;
    for(auto & layer_1 : commands){
        if(layer_1[0] == ID){
            does_it_have_id = true;
        }
    }
    bool does_it_have_title = false;
    for(auto & layer_1 : commands){
        if(layer_1[0] == TITLE){
            does_it_have_title = true;
        }
    }
    bool does_it_have_message = false;
    for(auto & layer_1 : commands){
        if(layer_1[0] == MESSAGE){
            does_it_have_message = true;
        }
    }
    bool does_it_have_image = false;
    for(auto & layer_1 : commands){
        if(layer_1[0] == IMAGE){
            does_it_have_image = true;
        }
    }

    return (does_it_have_id && does_it_have_title && does_it_have_message && does_it_have_image);
}