#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>

#define OK "OK"
#define EMPTY "Empty"
#define NOT_FOUND "Not Found"
#define BAD_REQUEST "Bad Request"
#define PERMISSION_DENIED "Permission Denied"
#define QUESTION_MARK "?"
#define GET "GET"
#define POST "POST"
#define DELETE "DELETE"
#define PUT "PUT"
#define LOGIN "login"
#define LOGOUT "logout"
#define ID "id"
#define PASSWORD "password"
#define COURSES "courses"
#define POST_SECOND_COMMAND "post"
#define TITLE "title"
#define MESSAGE "message"
#define PERSONAL_PAGE "personal_page"
#define POST_ID "post_id"
#define CONNECT "connect"
#define NOTIFICATION "notification"
#define UT_ACCOUNT "UT_account"
#define COURSE_OFFER "course_offer"
#define COURSE_ID "course_id"
#define PROFESSOR_ID "professor_id"
#define CAPACITY "capacity"
#define TIME "time"
#define EXAM_DATE "exam_date"
#define CLASS_NUMBER "class_number"
#define MY_COURSES "my_courses"

using namespace std;



// files/majors.csv
// files/students.csv
// files/courses.csv
// files/professors.csv
// files/majors.csv files/students.csv files/courses.csv files/professors.csv

// 810102566
// Shayan7812

int string_to_int(string str) {
    int num;
    stringstream ss(str);
    ss >> num;
    return num;
}


class MyException : public exception {
protected:
    string message;
public:
    MyException(const string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

class OkExeption : public MyException {
public:
    OkExeption() : MyException(OK) {}
};

class Empty : public MyException {
public:
    Empty() : MyException(EMPTY) {}
};

class NotFound : public MyException {
public:
    NotFound() : MyException(NOT_FOUND) {}
};

class BadRequest : public MyException {
public:
    BadRequest() : MyException(BAD_REQUEST) {}
};

class PermissionDenied : public MyException {
public:
    PermissionDenied() : MyException(PERMISSION_DENIED) {}
};

class Uniperson {
public:
    Uniperson(){
    }

    bool is_id_match(int id_){
        if(id == id_){
            return true;
        }else{
            return false;
        }
    }
    bool is_password_match(string password_){
        if(password == password_){
            return true;
        }else{
            return false;
        }
    }

    int am_i_loged_in(){
        return is_loged_int;
    }
    int get_id(){
        return id;
    }
    void set_loged(int x){
        is_loged_int = x;
    }
    void add_contacts(int id_){
        contacts.push_back(id_);
    }
protected:
    int id;
    string name;
    int major_id;
    string password;
    int is_loged_int = 0;
    vector<int> contacts;
    vector<vector<string>> notifications; // title & message
    vector<vector<string>> i_posted;
};

class UtAccount : public Uniperson{
public:
    UtAccount(){
        id = 0;
        password  = UT_ACCOUNT;
    }
    void test_UtAccount(){
        cout << "id: " << id << endl;
        cout << "password: " << password << endl;
    }
private:
};

class Student : public Uniperson  {
public:
    void student_csv_setup(int id_ ,string name_ , int major_id_ , int semester_ , string password_){
        id = id_;
        name = name_;
        major_id = major_id_;
        semester = semester_;
        password = password_;
    }
    void test_show(){
        cout << "sid: " << id << endl;
        cout << "name: "<< name << endl;
        cout << "major_id: "<< major_id << endl;
        cout << "semester: "<< semester << endl;
        cout << "password: "<< password << endl;
    }
private:
    int semester;
};

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

class Professor : public Uniperson{
public:
    void professor_csv_setup(int id_ ,string name_ , int major_id_ , string position_ , string password_){
        id = id_;
        name = name_;
        major_id = major_id_;
        position = position_;
        password = password_;
    }
    void test_show(){
        cout << "pid: " << id <<endl;
        cout << "name: " << name <<endl;
        cout << "major_id: " << major_id <<endl;
        cout << "position: " << position <<endl;
        cout << "password: " << password <<endl;
    }
private:
    string position;
};

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

class Course {
public:
    void major_csv_setup(int cid_ , string name_ , int credit_ , int prerequisite_ , vector<int> majors_id_ ){
        cid = cid_;
        name = name_;
        credit = credit_;
        prerequisite = prerequisite_;
        majors_id = majors_id_;
    }
    void test_show(){
        cout << "cid: " << cid << endl;
        cout << "name: " << name << endl;
        cout << "credit: " << credit << endl;
        cout << "prerequisite: " << prerequisite << endl;
        cout << "majors_id(s): ";
        for(vector<int>::size_type i = 0 ; i < majors_id.size() ; i++){
            cout << majors_id[i] << " ";
        }
        cout << endl;

    }
private:
    int cid;
    string name;
    int credit;
    int prerequisite;
    vector<int> majors_id;
};

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
        ptr_course->major_csv_setup(string_to_int(id) , name , string_to_int(credit) , string_to_int(prerequisite) , majors_ids);
        courses.emplace_back(ptr_course);
    }
    file.close();
}

class Major {
public:
    void major_csv_setup(int mid_ , string major_){
        mid = mid_;
        major = major_;
    }
    void test_show(){
        cout << "mid: " << mid << endl;
        cout << "major: "<< major << endl;
    }
private:
    int mid;
    string major;
};

void extract_majors_csv(string address, vector<Major*> &majors){
    fstream file(address);
    if (!file.is_open()) {
        cerr << "failed to open the majors file!!!";
    }
    string line;
    getline (file , line);
    while(getline(file , line)){
        stringstream ss;
        ss << line;
        string id;
        getline(ss , id , ',');
        string major;
        getline(ss , major);
        Major* major_ptr = new Major;
        major_ptr->major_csv_setup(string_to_int(id) , major);
        majors.emplace_back(major_ptr);
    }
    file.close();
}

vector<string> seperate_one_two_command(string command)
{
    stringstream ss;
    ss << command;
    string word;
    vector<string> commands;
    getline(ss, word, ' ');
    commands.push_back(word);
    getline(ss, word, ' ');
    commands.push_back(word);
    return commands;
}

void check_for_four_commands(string command){
    stringstream ss;
    ss << command;
    string word;
    getline(ss , word , ' ');
    if(!((word == GET) || (word == POST) || (word == DELETE) || (word == PUT))){
        throw BadRequest();
    }
}

void check_for_second_commands(string command){
    stringstream ss;
    ss << command;
    string word;
    getline(ss , word , ' ');
    getline(ss , word , ' ');
    if(!((word == LOGIN) || (word == LOGOUT) || (word == COURSES) || (word == POST_SECOND_COMMAND) || 
    (word == PERSONAL_PAGE) || (word == CONNECT) || (word == NOTIFICATION) || 
    (word == COURSE_OFFER) || (word == MY_COURSES))){
        throw NotFound();
    }
}


void check_for_quastion_mark(string command){
    stringstream ss;
    ss << command;
    string word;
    getline(ss , word , ' ');
    getline(ss , word , ' ');
    getline(ss , word , ' ');
    if(!(word == "?")){
        throw BadRequest();
    }
}
void login_setup(string arg_1_value , string arg_2_value , vector<Student *> &students, vector<Professor *> &professors, UtAccount *ut_account_ptr){
    for(auto &student : students){
        if(student->is_id_match(string_to_int(arg_1_value))){
            if(student->is_password_match(arg_2_value)){
                student->set_loged(1);
                throw OkExeption();
            }else{
                throw PermissionDenied();
            }
        }
    }
    for(auto &professor : professors){
        if(professor->is_id_match(string_to_int(arg_1_value))){
            if(professor->is_password_match(arg_2_value)){
                professor->set_loged(1);
                throw OkExeption();
            }else{
                throw PermissionDenied();
            }
        }
    }
    if(ut_account_ptr->is_id_match(string_to_int(arg_1_value))){
        if(ut_account_ptr->is_password_match(arg_2_value)){
            ut_account_ptr->set_loged(1);
            throw OkExeption();
        }else{
            throw PermissionDenied();
        }
    }
    throw NotFound();

}

void login_command(string command, vector<Student *> &students, vector<Professor *> &professors, UtAccount *ut_account_ptr)
{
    vector<string> commands = seperate_one_two_command(command);
    stringstream ss;
    ss << command;
    string word;
    getline(ss, word, '?');
    getline(ss, word, ' ');
    getline(ss, word, ' ');
    string arg_1 = word;
    getline(ss, word, ' ');
    string arg_1_value = word;
    getline(ss, word, ' ');
    string arg_2 = word;
    getline(ss, word, ' ');
    string arg_2_value = word;
    if ((commands[0] == POST) && (commands[1] == LOGIN))
    {
        if(!(((arg_1 == ID) && (arg_2 == PASSWORD)) || ((arg_2 == ID) && (arg_1 == PASSWORD)))){
            throw BadRequest();
        }
        else if((arg_1 == ID) && (arg_2 == PASSWORD)){
            login_setup(arg_1_value , arg_2_value ,students,professors,ut_account_ptr);
        }
        else if((arg_2 == ID) && (arg_1 == PASSWORD)){
            login_setup(arg_2_value , arg_1_value ,students,professors,ut_account_ptr);
        }
    }
}


bool is_it_login_command(string command)
{
    vector<string> commands = seperate_one_two_command(command);
    stringstream ss;
    ss << command;
    string word;
    getline(ss, word, '?');
    getline(ss, word, ' ');
    getline(ss, word, ' ');
    string arg_1 = word;
    getline(ss, word, ' ');
    string arg_1_value = word;
    getline(ss, word, ' ');
    string arg_2 = word;
    getline(ss, word, ' ');
    string arg_2_value = word;
    if ((commands[0] == POST) && (commands[1] == LOGIN))
    {
        if(((arg_1 == ID) && (arg_2 == PASSWORD)) || ((arg_2 == ID) && (arg_1 == PASSWORD))){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool is_anyone_loged_in(vector<Student *> students, vector<Professor *> professors, UtAccount *ut_account_ptr)
{
    bool result = false;
    for (auto &student : students)
    {
        if (student->am_i_loged_in())
        {
            result = true;
        }
    }
    for (auto &professor : professors)
    {
        if (professor->am_i_loged_in())
        {
            result = true;
        }
    }
    if (ut_account_ptr->am_i_loged_in())
    {
        result = true;
    }
    return result;
}



bool is_it_logout_command(string command){
    vector<string> commands = seperate_one_two_command(command);
    stringstream ss;
    ss << command;
    string word;
    int iteration = 0 ;
    while (getline(ss, word, ' '))
    {
        iteration ++;
    }
    if(iteration == 3){
        if((commands[0] == POST) && (commands[1] == LOGOUT)){
            return true;
        }else {
            return false;
        }
    }else {
        return false;
    }
}

void logout_command(string command, vector<Student *> &students, vector<Professor *> &professors, UtAccount *ut_account_ptr){
    vector<string> commands = seperate_one_two_command(command);
    stringstream ss;
    ss << command;
    string word;
    int iteration = 0 ;
    while (getline(ss, word, ' '))
    {
        iteration ++;
    }
    if((iteration == 3) && (commands[0] == POST) && (commands[1] == LOGOUT)){
        for(auto & student : students){
            if(student->am_i_loged_in()){
                student->set_loged(0);
            }
        }
        for(auto & professor : professors){
            if(professor->am_i_loged_in()){
                professor->set_loged(0);
            }
        }
        if(ut_account_ptr->am_i_loged_in()){
            ut_account_ptr->set_loged(0);
        }
        throw OkExeption();
    }   
}

void deallocate(vector<Major *> &majors , vector<Student *> &students , vector<Course *> &courses ,vector<Professor *> &professors , UtAccount *ut_account_ptr )
{
    for (Major *major_ptr : majors)
    {
        delete major_ptr;
    }
    majors.clear();
    for (Student *student_ptr : students)
    {
        delete student_ptr;
    }
    students.clear();
    for (Professor *proffesor_ptr : professors)
    {
        delete proffesor_ptr;
    }
    professors.clear();
    for (Course *course_ptr : courses)
    {
        delete course_ptr;
    }
    courses.clear();

    delete ut_account_ptr;
    ut_account_ptr = nullptr;
}




// ---------------------------------




int identify_user(vector<Student *> &students, vector<Professor *> &professors, UtAccount *ut_account_ptr){
    for(auto & student : students){
        if(student->am_i_loged_in()){
            return student->get_id();
        }
    }
    for(auto & professor : professors){
        if(professor->am_i_loged_in()){
            return professor->get_id();
        }
    }
    if(ut_account_ptr->am_i_loged_in()){
        return ut_account_ptr->get_id();
    }
    // error = -1
    // if there is no user loged in
    // this error handeled before but we can double check it
    return -1;
}

bool is_it_connect_command(string command){
    vector<string> commands;
    stringstream ss;
    ss << command;
    string word;
    int iteration = 0 ;
    while (getline(ss, word, ' '))
    {
        commands.push_back(word);
        iteration ++;
    }
    if(iteration == 5){
        if((commands[0] == POST) && (commands[1] == CONNECT) && (commands[3] == ID)){
            return true;
        }else {
            return false;
        }
    }else {
        return false;
    }
}

void connect_command(string command, vector<Student *> &students, vector<Professor *> &professors, UtAccount *ut_account_ptr){
    vector<string> commands;
    stringstream ss;
    ss << command;
    string word;
    int user_id = identify_user(students ,professors , ut_account_ptr);
    if(user_id == -1){
        throw PermissionDenied();
    }
    int iteration = 0 ;
    while (getline(ss, word, ' '))
    {
        commands.push_back(word);
        iteration ++;
    }
    // check for if the user enters his own id;
    if((iteration == 5) &&(commands[0] == POST) && (commands[1] == CONNECT) && (commands[3] == ID) ){
        for(auto &student : students){
            if((student->get_id() == string_to_int(commands[4]))){
                student->add_contacts(user_id);
                throw OkExeption();
            }
            if(student->get_id() == user_id){
                student->add_contacts(string_to_int(commands[4]));
                throw OkExeption();
            }
        }
        for(auto &professor : professors){
            if((professor->get_id() == string_to_int(commands[4]))){
                professor->add_contacts(user_id);
                throw OkExeption();
            }
            if(professor->get_id() == user_id){
                professor->add_contacts(string_to_int(commands[4]));
                throw OkExeption();
            }
        }
        if((ut_account_ptr->get_id() == string_to_int(commands[4]))){
            ut_account_ptr->add_contacts(user_id);
            throw OkExeption();
        }
        if(ut_account_ptr->get_id() == user_id){
            ut_account_ptr->add_contacts(string_to_int(commands[4]));
            throw OkExeption();
        }
    }
}

void run(vector<Student *> &students , vector<Professor *> &professors , UtAccount *ut_account_ptr){
    string command;
    while (true)
    {
        try{

            getline(cin, command);
            if(command == "qq"){
                break;
            }

            // first check
            check_for_four_commands(command);
            check_for_second_commands(command);
            check_for_quastion_mark(command);


            // login command
            // POST login ? id 810420432 password halalalaylalalay
            if(is_it_login_command(command)){
                if(is_anyone_loged_in(students ,professors , ut_account_ptr)){
                    throw PermissionDenied();
                }
            }
            login_command(command ,students ,professors , ut_account_ptr);
            // logout command 
            // POST logout ?
            if(is_it_logout_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
            }
            logout_command(command ,students ,professors , ut_account_ptr);
            // POST connect ? id 810420500
            // connect command
            if(is_it_connect_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
            }
            //connect_command(command ,students ,professors , ut_account_ptr);
            connect_command(command ,students ,professors , ut_account_ptr);
            // this should be at the end of the while loop: throw BadRequest();
            throw BadRequest();
        }
        catch(const MyException& e){
            cout <<e.what() << endl;
            
        }
    }
}




int main(int argc, char *argv[])
{
    argc++;
    argc--;
    vector<Major *> majors;
    vector<Student *> students;
    vector<Course *> courses;
    vector<Professor *> professors;
    UtAccount *ut_account_ptr = new UtAccount();
    extract_majors_csv(argv[1], majors);
    extract_students_csv(argv[2], students);
    extract_courses_csv(argv[3], courses);
    extract_professors_csv(argv[4], professors);
    run(students ,professors , ut_account_ptr);
    deallocate(majors ,students , courses ,professors , ut_account_ptr );

    return 0;
}