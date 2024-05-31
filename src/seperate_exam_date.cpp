#include "global.hpp"

vector<int> seperate_exam_date(string exam_date){
    vector<int> exam_date_vec;
    string day;
    string month;
    string year;
    stringstream ss;
    ss << exam_date;
    getline(ss, year , '/');
    getline(ss, month , '/');
    getline(ss, day);
    exam_date_vec.push_back(string_to_int(day));
    exam_date_vec.push_back(string_to_int(month));
    exam_date_vec.push_back(string_to_int(year));
    return exam_date_vec;
}