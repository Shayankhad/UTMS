#include "global.hpp"

bool is_it_professor(int id , vector<Professor *> professors ){
    for(auto & professor : professors ){
        if(professor->get_id() == id){
            return true;
        }
    }
    return false;
}