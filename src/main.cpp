#include "global.hpp"

void extract_students_csv(string address, vector<Student*> &students){
    fstream file(address);
    if (!file.is_open()) {
        cerr << "failed to open the students file!!!";
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
        string major_id;
        getline(ss , major_id , ',');
        string semester;
        getline(ss , semester , ',');
        string password;
        getline(ss , password);
        Student * ptr_student = new Student;
        ptr_student->student_csv_setup(string_to_int(id), name , string_to_int(major_id) , string_to_int(semester) , password);
        students.emplace_back(ptr_student);
    }
    file.close();
}

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