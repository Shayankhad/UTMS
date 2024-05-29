#include "global.hpp"

void extract_courses_csv(string address , vector<Course*> &courses){
    fstream file(address);
    if (!file.is_open()) {
        cerr << "failed to open the courses file!!!";
    }
    string line;
    getline (file , line);
    while(getline(file , line)){
        stringstream ss;
        ss << line;
        string id;
        getline(ss , id , ',');
        string name;
        getline(ss , name , ',');
        string credit;
        getline(ss , credit , ',');
        string prerequisite;
        getline(ss , prerequisite , ',');
        vector<int> majors_ids;
        string majors_id;
        while(getline(ss , majors_id , ';')){
            majors_ids.push_back(string_to_int(majors_id));
        }
        Course* ptr_course = new Course;
        ptr_course->course_csv_setup(string_to_int(id) , name , string_to_int(credit) , string_to_int(prerequisite) , majors_ids);
        courses.emplace_back(ptr_course);
    }
    file.close();
}