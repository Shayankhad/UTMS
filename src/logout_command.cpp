#include "global.hpp"

void logout_command(string command, vector<Student *> &students, vector<Professor *> &professors, UtAccount *ut_account_ptr){
    vector<string> commands = seperate_one_two_command(command);
    stringstream ss;
    ss << command;
    string word;
    int iteration = 0 ;
    while (getline(ss, word, ' '))
    {
        iteration ++;
    }
    if((iteration == 3) && (commands[0] == POST) && (commands[1] == LOGOUT)){
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
}