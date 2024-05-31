#ifndef PRESENTED_COURSE_HPP
#define PRESENTED_COURSE_HPP
#include "global.hpp"
class PresentedCourse{
public:
    PresentedCourse(int course_id_ , string course_name_ , int professor_id_ , string professor_name_
    , int capacity_ , string day_ , vector<int> start_finish_hour_ , vector<int> exam_date_ 
    , int class_number_  , int presented_course_id_ , int prerequisite_ ) : course_id(course_id_) , course_name(course_name_) 
    , professor_id(professor_id_) , professor_name(professor_name_) ,capacity(capacity_) , day(day_) , start_finish_hour(start_finish_hour_)
    , exam_date(exam_date_) , class_number(class_number_ ) , presented_course_id(presented_course_id_) , prerequisite(prerequisite_) {
    }

    void show_type_1(){
        cout << presented_course_id << " ";
        cout << course_name << " ";
        cout << capacity << " ";
        cout << professor_name << endl;
    }

    //<id> <name> <capacity> <professor> <time> <exam_date> <class_number> |
// 7 Advanced Programming 110 Ramtin Khosravi Tuesday:10-12 1403/4/2 1

    void show_type_2(){
        cout << presented_course_id << " ";
        cout << course_name << " ";
        cout << capacity << " ";
        cout << professor_name << " ";
        cout << day << ":" << start_finish_hour[0] << "-" << start_finish_hour[1] << " ";
        cout << exam_date[2] << "/" << exam_date[1] << "/" << exam_date[0] << " ";
        cout << class_number << endl;
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

    int get_presented_course_id(){
        return presented_course_id;
    }

    bool is_presented_course_match(int id_){
        if(presented_course_id == id_){
            return true;
        }
        return false;
    }

    bool check_semester(int semester){
        if(semester < prerequisite){
            return false;
        }
        return true;
    }

private:
    int course_id;
    string course_name;
    int professor_id;
    string professor_name;
    int capacity;
    string day;
    vector<int> start_finish_hour;
    vector<int> exam_date;
    int class_number;
    int presented_course_id;
    int prerequisite;
};
#endif