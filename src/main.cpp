#include "global.hpp"

int main (int argc , char* argv[]){
    argc++;
    argc--;
    vector<Major*> majors;
    vector<Student*> students;
    vector<Course*> courses;
    vector<Professor*> professors;
    extract_majors_csv(argv[1] , majors);
    extract_students_csv(argv[2] , students);
    extract_courses_csv(argv[3] , courses);
    extract_professors_csv(argv[4] , professors);
    // UT_account
}