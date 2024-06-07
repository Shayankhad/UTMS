#include "global.hpp"

vector<vector<string>> sort_course_post_type_two_command(vector<vector<string>> un_sorted){
    vector<vector<string>> sorted(4);
    for(vector<std::vector<std::__cxx11::basic_string<char> > >::size_type i = 0 ; i < un_sorted.size() ; i++){
        if(un_sorted[i][0] == ID){
            sorted[0] =un_sorted[i];
        }
        if(un_sorted[i][0] == TITLE){
            sorted[1] =un_sorted[i];
        }
        if(un_sorted[i][0] == MESSAGE){
            sorted[2] =un_sorted[i];
        }
        if(un_sorted[i][0] == IMAGE){
            sorted[3] =un_sorted[i];
        }
    }
    return sorted;
}