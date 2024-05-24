#include "global.hpp"


vector<string> one_two_command(string command){
    stringstream ss;
    ss << command;
    string word;
    vector<string> commands;
    getline(ss , word , ' ');
    commands.push_back(word);
    getline(ss , word , ' ');
    commands.push_back(word);
    return commands;
}

void login_command(string command){
    // POST login ? id 810102612 password meoow
    vector<string> commands = one_two_command(command);
    stringstream ss;
    ss << command;
    string word;
    getline(ss, word , '?');
    getline(ss, word , ' ');
    getline(ss, word , ' ');
    string arg_1 = word;
    getline(ss, word , ' ');
    string arg_1_value = word;
    getline(ss, word , ' ');
    string arg_2 = word;
    getline(ss, word , ' ');
    string arg_2_value = word;
    if((commands[0] == POST) && (commands[1] == LOGIN) && (arg_1 == ID) && (arg_2 == PASSWORD)){
        cout << "hi!" << endl;
    }
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
    UtAccount* ut_account_ptr = new UtAccount;
    string command;
    while(true){
        getline(cin , command);
        if(command == "qq"){
            break;
        }
        login_command(command);
    }

    return 0;
}