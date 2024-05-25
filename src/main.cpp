#include "global.hpp"

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

void login_setup(string arg_1_value , string arg_2_value , vector<Student *> &students, vector<Professor *> &professors, UtAccount *ut_account_ptr){
    for(auto &student : students){
        if(student->is_id_match(string_to_int(arg_1_value))){
            if(student->is_password_match(arg_2_value)){
                student->set_loged(loged_in);
                throw OkExeption();
            }else{
                throw PermissionDenied();
            }
        }
    }
    for(auto &professor : professors){
        if(professor->is_id_match(string_to_int(arg_1_value))){
            if(professor->is_password_match(arg_2_value)){
                professor->set_loged(loged_in);
                throw OkExeption();
            }else{
                throw PermissionDenied();
            }
        }
    }
    if(ut_account_ptr->is_id_match(string_to_int(arg_1_value))){
        if(ut_account_ptr->is_password_match(arg_2_value)){
            ut_account_ptr->set_loged(loged_in);
            throw OkExeption();
        }else{
            throw PermissionDenied();
        }
    }
    throw NotFound();

}

void login_command(string command, vector<Student *> &students, vector<Professor *> &professors, UtAccount *ut_account_ptr)
{
    // POST login ? id 810102612 password ImtheproblemItsme
    // POST login ? password ImtheproblemItsme id 810102612
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
    cout << arg_2_value << endl << arg_1_value << endl;
    if ((commands[0] == POST) && (commands[1] == LOGIN))
    {
        if((arg_1 == ID) && (arg_2 == PASSWORD)){
            login_setup(arg_1_value , arg_2_value ,students,professors,ut_account_ptr);
        }
        else if((arg_2 == ID) && (arg_1 == PASSWORD)){
            login_setup(arg_2_value , arg_1_value ,students,professors,ut_account_ptr);
        }
    }
}


// bool is_it_login_command(string command, vector<Student *> students, vector<Professor *> professors, UtAccount *ut_account_ptr)
// {
//     vector<string> commands = seperate_one_two_command(command);
//     stringstream ss;
//     ss << command;
//     string word;
//     getline(ss, word, '?');
//     getline(ss, word, ' ');
//     getline(ss, word, ' ');
//     string arg_1 = word;
//     getline(ss, word, ' ');
//     string arg_1_value = word;
//     getline(ss, word, ' ');
//     string arg_2 = word;
//     getline(ss, word, ' ');
//     string arg_2_value = word;
//     if ((commands[0] == POST) && (commands[1] == LOGIN))
//     {
//         if((arg_1 == ID) && (arg_2 == PASSWORD)){
//             return true;
//         }
//         if((arg_2 == ID) && (arg_1 == PASSWORD)){
//             return true;
//         }
//     }else{
//         return false;
//     }
// }

// bool is_anyone_loged_in(vector<Student *> students, vector<Professor *> professors, UtAccount *ut_account_ptr)
// {
//     bool result = false;
//     for (auto &student : students)
//     {
//         if (student->am_i_loged_in())
//         {
//             result = true;
//         }
//     }
//     for (auto &professor : professors)
//     {
//         if (professor->am_i_loged_in())
//         {
//             result = true;
//         }
//     }
//     if (ut_account_ptr->am_i_loged_in())
//     {
//         result = true;
//     }
//     return result;
// }

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
        try{
            getline(cin, command);
            if(command == "qq"){
                break;
            }
            check_for_four_commands(command);
            check_for_second_commands(command);
            login_command(command ,students ,professors , ut_account_ptr);
        }
        catch(const MyException& e){
            cout <<e.what() << endl;
        }
    }
    deallocate(majors ,students , courses ,professors , ut_account_ptr );

    return 0;
}