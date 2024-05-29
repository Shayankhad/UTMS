#include "global.hpp"


void logout_command(vector<Student *> &students, vector<Professor *> &professors, UtAccount *ut_account_ptr){
    for(auto & student : students){
        if(student->am_i_loged_in()){
            student->set_loged(0);
        }
    }
    for(auto & professor : professors){
        if(professor->am_i_loged_in()){
            professor->set_loged(0);
        }
    }
    if(ut_account_ptr->am_i_loged_in()){
        ut_account_ptr->set_loged(0);
    }
    throw OkExeption();
}