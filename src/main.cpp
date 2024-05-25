#include "global.hpp"




bool is_anyone_loged_in(vector<Student *> students, vector<Professor *> professors, UtAccount *ut_account_ptr)
{
    bool result = false;
    for (auto &x : students)
    {
        if (x->am_i_loged_in())
        {
            result = true;
        }
    }
    for (auto &x : professors)
    {
        if (x->am_i_loged_in())
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

vector<string> one_two_command(string command)
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
bool check_for_four_commands(string command){
    stringstream ss;
    ss << command;
    string word;
    getline(ss , word , ' ');
    if(!((word == GET) || (word == POST) || (word == DELETE) || (word == PUT))){
        cerr << BAD_REQUEST << endl;
        return false;
    }
    return true;
}
void login_command(string command, vector<Student *> students, vector<Professor *> professors, UtAccount *ut_account_ptr)
{
    // POST login ? id 810102612 password ImtheproblemItsme
    // POST login ? password ImtheproblemItsme id 810102612
    vector<string> commands = one_two_command(command);
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
        if((arg_1 == ID) && (arg_2 == PASSWORD)){
            for(auto &x : students){
                x->check_login(string_to_int(arg_1_value) , arg_2_value);
            }
            for(auto &x : professors){
                x->check_login(string_to_int(arg_1_value) , arg_2_value);
            }
            ut_account_ptr->check_login(string_to_int(arg_1_value) , arg_2_value);
        }
        if((arg_2 == ID) && (arg_1 == PASSWORD)){
            for(auto &x : students){
                x->check_login(string_to_int(arg_2_value) , arg_1_value);
            }
            for(auto &x : professors){
                x->check_login(string_to_int(arg_2_value) , arg_1_value);
            }
            ut_account_ptr->check_login(string_to_int(arg_2_value) , arg_1_value);
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
    UtAccount *ut_account_ptr = new UtAccount;
    extract_majors_csv(argv[1], majors);
    extract_students_csv(argv[2], students);
    extract_courses_csv(argv[3], courses);
    extract_professors_csv(argv[4], professors);
    string command;
    while (true)
    {
        getline(cin, command);
        if (command == "qq")
        {
            break;
        }
        if(!check_for_four_commands(command)){
            continue;
        }
        login_command(command, students, professors, ut_account_ptr);
        cout << is_anyone_loged_in(students, professors, ut_account_ptr) << endl;
    }

    return 0;
}