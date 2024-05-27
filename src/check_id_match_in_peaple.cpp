#include "global.hpp"

bool check_id_match_in_peaple (int id ,vector<Student *> students, vector<Professor *> professors, UtAccount *ut_account_ptr ){
    for(auto & student : students){
        if(student->is_id_match(id)){
            return true;
        }
    }
    for(auto & professor : professors){
        if(professor->is_id_match(id)){
            return true;
        }
    }
    if(ut_account_ptr->is_id_match(id)){
        return true;
    }
    return false;
}