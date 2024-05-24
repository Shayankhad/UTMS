#include "global.hpp"

void extract_professors_csv(string address , vector<Professor*> &professors){
    fstream file(address);
    if (!file.is_open()) {
        cerr << "failed to open the professors file!!!";
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
        string position;
        getline(ss , position , ',');
        string password;
        getline(ss , password , ',');
        Professor* ptr_professor = new Professor;
        ptr_professor->professor_csv_setup(string_to_int(id) , name , string_to_int(major_id) , position , password );
        professors.emplace_back(ptr_professor);
    }
    file.close();
}

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
    for (auto & x : professors){
        x->test_show();
    }
}