#include "global.hpp"

void add_profile_photo_command(string command , int user_id , vector<Student *> &students , vector<Professor *> &professors ,  UtAccount *ut_account_ptr){
    vector<string> commands;
    string word;
    stringstream ss;
    ss << command;
    while (getline(ss, word, ' '))
    {
        if (!word.empty())
        {
            commands.push_back(word);
        }
    }

    string profile_address = commands[4];
    for(auto & student : students){
        if(student->get_id() == user_id){
            student->add_profile_photo(profile_address);
        }
    }
    for(auto & professor : professors){
        if(professor->get_id() == user_id){
            professor->add_profile_photo(profile_address);
        }
    }
    if(ut_account_ptr->get_id() == user_id){
        ut_account_ptr->add_profile_photo(profile_address);
    }
    throw OkExeption();
}