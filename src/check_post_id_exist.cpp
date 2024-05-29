#include "global.hpp"

void check_post_id_exist(int target_post_id ,vector<Student *> &students, vector<Professor *> &professors, UtAccount *ut_account_ptr ){
    bool does_post_id_match = false;
    int user_id = identify_user(students ,professors , ut_account_ptr);
    for(auto & student : students){
        if(student->get_id() == user_id){
            if(student->is_post_id_match(target_post_id)){
                does_post_id_match = true;
            }
        }
    }
    for(auto & professor : professors){
        if(professor->get_id() == user_id){
            if(professor->is_post_id_match(target_post_id)){
                does_post_id_match = true;
            }
        }
    }
    if(ut_account_ptr->get_id() == user_id){
        if(ut_account_ptr->is_post_id_match(target_post_id)){
            does_post_id_match = true;
        }
    }

    if(does_post_id_match == false){
        throw NotFound();
    }
}