#include "global.hpp"

void add_notif_handeling(vector<Student *> &students , vector<Professor *> &professors , UtAccount *ut_account_ptr , string type ,int user_id ){
    
    for(auto & student : students){
        if(student->get_id() == user_id){
            for(auto & s : students){
                if(student->am_i_in_contact(s->get_id())){
                    s->add_notif(student->get_id() , student->get_name() , type);
                }
            }
            for(auto & p : professors){
                if(student->am_i_in_contact(p->get_id())){
                    p->add_notif(student->get_id() , student->get_name() , type);
                }
            }

            if(student->am_i_in_contact(ut_account_ptr->get_id())){
                ut_account_ptr->add_notif(student->get_id() , student->get_name() , type);
            }
        }
    }

    
    for(auto & professor : professors){
        if(professor->get_id() == user_id){
            for(auto & s : students){
                if(professor->am_i_in_contact(s->get_id())){
                    s->add_notif(professor->get_id() , professor->get_name() , type);
                }
            }
            for(auto & p : professors){
                if(professor->am_i_in_contact(p->get_id())){
                    p->add_notif(professor->get_id() , professor->get_name() , type);
                }
            }

            if(professor->am_i_in_contact(ut_account_ptr->get_id())){
                ut_account_ptr->add_notif(professor->get_id() , professor->get_name() , type);
            }
        }
    }

    
    if(ut_account_ptr->get_id() == user_id){
        
        for(auto & s : students){
            if(ut_account_ptr->am_i_in_contact(s->get_id())){
                s->add_notif(ut_account_ptr->get_id() , ut_account_ptr->get_name() , type);
            }
        }
        for(auto & p : professors){
            if(ut_account_ptr->am_i_in_contact(p->get_id())){
                p->add_notif(ut_account_ptr->get_id() , ut_account_ptr->get_name() , type);
            }
        }

        if(ut_account_ptr->am_i_in_contact(ut_account_ptr->get_id())){
            ut_account_ptr->add_notif(ut_account_ptr->get_id() , ut_account_ptr->get_name() , type);
        }
    } 
}