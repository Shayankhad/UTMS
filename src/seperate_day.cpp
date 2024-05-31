#include "global.hpp"

string seperate_day(string time){
    string day;
    stringstream ss;
    ss << time;
    getline(ss , day , ':' );
    return day;
}