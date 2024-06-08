#include "global.hpp"

vector<vector<string>> sort_show_course_post_args(vector<vector<string>> un_sorted){
    vector<vector<string>> sorted(2);
    for(vector<std::vector<std::__cxx11::basic_string<char> > >::size_type i = 0 ; i < un_sorted.size() ; i++){
        if(un_sorted[i][0] == ID){
            sorted[0] =un_sorted[i];
        }
        if(un_sorted[i][0] == POST_ID){
            sorted[1] =un_sorted[i];
        }
    }
    return sorted;
}