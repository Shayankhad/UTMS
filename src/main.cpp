#include "global.hpp"



int main (int argc , char* argv[]){
    argc++;
    argc--;
    vector<Major*> majors;
    vector<Student*> students;
    extract_majors_csv(argv[1] , majors);
    extract_students_csv(argv[2] ,students);
    for (auto & x : students){
        x->test_show();
    }
}