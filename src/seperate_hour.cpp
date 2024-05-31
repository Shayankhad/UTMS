#include "global.hpp"

vector<int> seperate_hour(string time){
    string day;
    stringstream ss;
    ss << time;
    getline(ss , day , ':' );
    string start;
    getline(ss, start , '-');
    string finish;
    getline(ss, finish);
    vector<int> hour;
    hour.push_back(string_to_int(start));
    hour.push_back(string_to_int(finish));
    return hour;
}