#include "global.hpp"



int main (int argc , char* argv[]){
    argc++;
    argc--;
    vector<Major*> majors;
    vector<Student*> students;
    vector<Course*> courses;
    extract_majors_csv(argv[1] , majors);
    extract_students_csv(argv[2] , students);
    extract_courses_csv(argv[3] , courses);
    for (auto & x : courses){
        x->test_show();
    }
}