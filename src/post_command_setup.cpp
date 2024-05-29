#include "global.hpp"


void post_command_setup(int user_id , string arg_1_value , string arg_2_value , vector<Student *> &students, vector<Professor *> &professors, UtAccount *ut_account_ptr ){
    for(auto & student : students){
        if(student->get_id() == user_id){
            student->make_post(arg_1_value , arg_2_value);
            for(auto & s : students){
                if(student->am_i_in_contact(s->get_id())){
                    s->add_notif(student->get_id() , student->get_name() , NEW_POST );
                }   
            }
            for(auto & p : professors){ 
                if(student->am_i_in_contact(p->get_id())){
                    p->add_notif(student->get_id() , student->get_name() , NEW_POST );
                }
            }
            if(student->am_i_in_contact(ut_account_ptr->get_id())){
                ut_account_ptr->add_notif(student->get_id() , student->get_name() , NEW_POST ); 
            }
        }
    }

    for(auto & professor : professors){
        if(professor->get_id() == user_id){
            professor->make_post(arg_1_value , arg_2_value);
            for(auto & s : students){
                if(professor->am_i_in_contact(s->get_id())){
                    s->add_notif(professor->get_id() , professor->get_name() , NEW_POST );
                }   
            }
            for(auto & p : professors){ 
                if(professor->am_i_in_contact(p->get_id())){
                    p->add_notif(professor->get_id() , professor->get_name() , NEW_POST );
                }
            }
            if(professor->am_i_in_contact(ut_account_ptr->get_id())){
                ut_account_ptr->add_notif(professor->get_id() , professor->get_name() , NEW_POST ); 
            }
        }
    }

    if(ut_account_ptr->get_id() == user_id){
        ut_account_ptr->make_post(arg_1_value , arg_2_value);
        for(auto & s : students){
            if(ut_account_ptr->am_i_in_contact(s->get_id())){
                s->add_notif(ut_account_ptr->get_id() , ut_account_ptr->get_name() , NEW_POST );
            }   
        }
        for(auto & p : professors){ 
            if(ut_account_ptr->am_i_in_contact(p->get_id())){
                p->add_notif(ut_account_ptr->get_id() , ut_account_ptr->get_name() , NEW_POST );
            }
        }
        if(ut_account_ptr->am_i_in_contact(ut_account_ptr->get_id())){
            ut_account_ptr->add_notif(ut_account_ptr->get_id() , ut_account_ptr->get_name() , NEW_POST ); 
        }
    }
}