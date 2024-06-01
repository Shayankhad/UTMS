#include "global.hpp"

void show_post_command(string command , vector<Student *> students , vector<Professor *> professors
, UtAccount *ut_account_ptr ,  vector<PresentedCourse *> presented_course , vector<Major *> majors ){
    vector<string> commands;
    stringstream ss;
    ss << command;
    string word;
    while (getline(ss, word, ' '))
    {
        if(!(word == "")){
            commands.push_back(word);
        }
    }
    
    if((commands[3] == ID) && (commands[5] == POST_ID)){
        if(check_number_type(commands[4]) != 1){
            throw BadRequest();
        }
        int user_id = string_to_int(commands[4]);
        if(user_id <= 0){
            throw BadRequest();
        }
        if(check_number_type(commands[6]) != 1){
            throw BadRequest();
        }
        int post_id = string_to_int(commands[6]);
        if(post_id <= 0){
            throw BadRequest();
        }

        if(!check_id_match_in_peaple(user_id , students , professors , ut_account_ptr)){
            throw NotFound();
        }
        for(auto & student : students){
            if(student->get_id() == user_id){
                check_post_id_exist(post_id , students , professors , ut_account_ptr);
            }
        }
        show_post_page_command(user_id , post_id , students , professors , ut_account_ptr ,presented_course , majors);
    }
    if((commands[5] == ID) && (commands[3] == POST_ID)){
        if(check_number_type(commands[6]) != 1){
            throw BadRequest();
        }
        int user_id = string_to_int(commands[6]);
        if(user_id <= 0){
            throw BadRequest();
        }
        if(check_number_type(commands[4]) != 1){
            throw BadRequest();
        }
        int post_id = string_to_int(commands[4]);
        if(post_id <= 0){
            throw BadRequest();
        }

        if(!check_id_match_in_peaple(user_id , students , professors , ut_account_ptr)){
            throw NotFound();
        }
        for(auto & student : students){
            if(student->get_id() == user_id){
                check_post_id_exist(post_id , students , professors , ut_account_ptr);
            }
        }
        show_post_page_command(user_id , post_id , students , professors , ut_account_ptr ,presented_course , majors);
    }
}