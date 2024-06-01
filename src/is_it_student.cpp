#include "global.hpp"


bool is_it_student(int user_id ,vector<Student *> students ){
    for(auto & student : students){
        if(student->get_id() == user_id){
            return true;
        }
    }
    return false;
}