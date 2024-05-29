#include "global.hpp"

void set_ut_account_ptr_contacts(vector<Student *> &students , vector<Professor *> &professors , UtAccount *ut_account_ptr){
    for(auto & student : students){
        ut_account_ptr->add_contacts(student->get_id());
        student->add_contacts(ut_account_ptr->get_id());
    }
    for(auto & professor : professors){
        ut_account_ptr->add_contacts(professor->get_id());
        professor->add_contacts(ut_account_ptr->get_id());
    }
}