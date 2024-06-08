#include "global.hpp"

vector<vector<string>> sort_ta_form_args(vector<vector<string>> un_sorted){
    vector<vector<string>> sorted(2);
    for(vector<std::vector<std::__cxx11::basic_string<char> > >::size_type i = 0 ; i < un_sorted.size() ; i++){
        if(un_sorted[i][0] == COURSE_ID){
            sorted[0] = un_sorted[i];
        }
        if(un_sorted[i][0] == MESSAGE){
            sorted[1] = un_sorted[i];
        }
    }
    return sorted;
}