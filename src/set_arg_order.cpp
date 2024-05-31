#include "global.hpp"
bool set_arg_order(vector<int> &arg_order , vector<vector<string>> arg_commands ){
    int turn = 1;
    if(turn == 1){
        for(vector<__cxx11::basic_string<char>>::size_type a = 0 ; a < arg_commands.size() ; a ++){
            if((arg_commands[a][0] == COURSE_ID) ){
                arg_order.push_back(a);
                turn ++;
                break;
            }
        }
    }
    if(turn == 2){
        for(vector<__cxx11::basic_string<char>>::size_type a = 0 ; a < arg_commands.size() ; a ++){
            if((arg_commands[a][0] == PROFESSOR_ID) ){
                arg_order.push_back(a);
                turn ++;
                break;
            }
        }
    }
    if(turn == 3){
        for(vector<__cxx11::basic_string<char>>::size_type a = 0 ; a < arg_commands.size() ; a ++){
            if((arg_commands[a][0] == CAPACITY) ){
                arg_order.push_back(a);
                turn ++;
                break;
            }
        }
    }
    if(turn == 4){
        for(vector<__cxx11::basic_string<char>>::size_type a = 0 ; a < arg_commands.size() ; a ++){
            if((arg_commands[a][0] == TIME) ){
                arg_order.push_back(a);
                turn ++;
                break;
            }
        }
    }
    if(turn == 5){
        for(vector<__cxx11::basic_string<char>>::size_type a = 0 ; a < arg_commands.size() ; a ++){
            if((arg_commands[a][0] == EXAM_DATE) ){
                arg_order.push_back(a);
                turn ++;
                break;
            }
        }
    }
    if(turn == 6){
        for(vector<__cxx11::basic_string<char>>::size_type a = 0 ; a < arg_commands.size() ; a ++){
            if((arg_commands[a][0] == CLASS_NUMBER) ){
                arg_order.push_back(a);
                turn ++;
                break;
            }
        }
    }
    if(turn == 7){
        return true;
    }
    
    return false;
}