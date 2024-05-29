#include "global.hpp"


void notificaiton_command(vector<Student *> &students , vector<Professor *> &professors , UtAccount *ut_account_ptr){
    bool is_notif_printed = false;
    int user_id = identify_user(students ,professors , ut_account_ptr);
    for(auto & student: students){
        if(student->get_id() == user_id){
            if(!student->is_notifications_empty()){
                is_notif_printed = true;
                student->show_notif_vec();
            }
        }
    }
    for(auto & professor: professors){
        if(professor->get_id() == user_id){
            if(!professor->is_notifications_empty()){
                is_notif_printed = true;
                professor->show_notif_vec();
            }
        }
    }
    if(ut_account_ptr->get_id() == user_id){
        if(!ut_account_ptr->is_notifications_empty()){
            is_notif_printed = true;
            ut_account_ptr->show_notif_vec();
        }
    }
    if(!is_notif_printed){
        throw Empty();
    }
}