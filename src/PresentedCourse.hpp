#ifndef PRESENTED_COURSE_HPP
#define PRESENTED_COURSE_HPP
#include "global.hpp"
class PresentedCourse{
public:
    PresentedCourse(int course_id_ , int professor_id_ ,int capacity_
    , string day_ , vector<int> start_finish_hour_ , vector<int> exam_date_ 
    , int class_number_  ) : course_id(course_id_) , professor_id(professor_id_) 
    , capacity(capacity_) , day(day_) , start_finish_hour(start_finish_hour_)
    , exam_date(exam_date_) , class_number(class_number_) {}

    void test_show(){
        cout << "course_id: " << course_id << endl;
        cout << "professor_id: " << professor_id << endl;
        cout << "capacity: " << capacity << endl;
        cout << "day: " << day << endl;
        cout << "start hour: " << start_finish_hour[0] << " finish hour: " << start_finish_hour[1] << endl;
        cout << "day of exam date: " << exam_date[0] << endl;
        cout << "month of exam date: " << exam_date[1] << endl;
        cout << "year of exam date: " << exam_date[2] << endl;
        cout << "class_number: " << class_number << endl;
    }

    bool check_start_and_finish_time_class_interference( vector<int> hour_ , string day_ , int proffesor_id_){
        if(proffesor_id_ == professor_id){
            if(day_ == day){
                for(float i = hour_[0] + 1 ; i < hour_[1] ; i = i + 0.5 ){
                    if(((start_finish_hour[0] < i) && (i < start_finish_hour[1]))){
                        return false;
                    }
                }
            }
        }

        return true;
    }

private:
    int course_id;
    int professor_id;
    int capacity;
    string day;
    vector<int> start_finish_hour;
    vector<int> exam_date;
    int class_number;
};
#endif