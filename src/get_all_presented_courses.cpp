#include "global.hpp"

vector<int> get_all_presented_courses(vector<Professor *> &professors){
    vector<int> all_courses;
    for(auto & professor : professors){
        for(auto & x : professor->get_token_courses()){
            all_courses.push_back(x);
        }
    }
    return all_courses;
}