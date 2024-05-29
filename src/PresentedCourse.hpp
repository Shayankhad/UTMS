#ifndef PRESENTED_COURSE_HPP
#define PRESENTED_COURSE_HPP
#include "global.hpp"
class PresentedCourse{
public:
    PresentedCourse(int course_id_ , int professor_id_ ,int capacity_
    , string day_ , vector<int> start_finish_hour_ , string exam_date_ 
    , int class_number_  ) : course_id(course_id_) , professor_id(professor_id_) 
    , capacity(capacity_) , day(day_) , start_finish_hour(start_finish_hour_)
    , exam_date(exam_date_) , class_number(class_number_) {}

    void test_show(){
        cout << "course_id: " << course_id << endl;
        cout << "professor_id: " << professor_id << endl;
        cout << "capacity: " << capacity << endl;
        cout << "day: " << day << endl;
        cout << "start hour: " << start_finish_hour[0] << " finish hour: " << start_finish_hour[1] << endl;
        cout << "exam_date: " << exam_date << endl;
        cout << "class_number: " << class_number << endl;
    }
private:
    int course_id;
    int professor_id;
    int capacity;
    string day;
    vector<int> start_finish_hour;
    string exam_date;
    int class_number;
};
#endif