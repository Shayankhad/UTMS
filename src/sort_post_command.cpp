#include "global.hpp"

vector<vector<string>> sort_post_command(string arg_1 , string arg_2 , string arg_3
, string arg_1_value , string arg_2_value , string arg_3_value){
    vector<vector<string>> un_sorted;
    un_sorted.push_back({arg_1 , arg_1_value});
    un_sorted.push_back({arg_2 , arg_2_value});
    un_sorted.push_back({arg_3 , arg_3_value});
    vector<vector<string>> sorted(3);
    for(vector<std::vector<std::__cxx11::basic_string<char> > >::size_type i = 0 ; i < un_sorted.size() ; i++){
        if(un_sorted[i][0] == TITLE){
            sorted[0] =un_sorted[i];
        }
        if(un_sorted[i][0] == MESSAGE){
            sorted[1] =un_sorted[i];
        }
        if(un_sorted[i][0] == IMAGE){
            sorted[2] =un_sorted[i];
        }
    }
    return sorted;
}