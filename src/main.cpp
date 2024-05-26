#include "global.hpp"

// is_it_logout_command
// logout_command
// you have to use is_anyone_loged_in to check nobody logout from nothing
// 
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
                student->set_loged(didnt_loged_in);
            }
        }
        for(auto & professor : professors){
            if(professor->am_i_loged_in()){
                professor->set_loged(didnt_loged_in);
            }
        }
        if(ut_account_ptr->am_i_loged_in()){
            ut_account_ptr->set_loged(didnt_loged_in);
        }
        throw OkExeption();
    }   
}


void run(vector<Student *> &students , vector<Professor *> &professors , UtAccount *ut_account_ptr){
    string command;
    while (true)
    {
        try{
            // POST login ? id 810420432 password halalalaylalalay
            getline(cin, command);
            if(command == "qq"){
                break;
            }

            // first check
            check_for_four_commands(command);
            check_for_second_commands(command);
            check_for_quastion_mark(command);


            // login command
            if(is_it_login_command(command)){
                if(is_anyone_loged_in(students ,professors , ut_account_ptr)){
                    throw PermissionDenied();
                }
            }
            login_command(command ,students ,professors , ut_account_ptr);
            // logout command 
            if(is_it_logout_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
            }
            logout_command(command ,students ,professors , ut_account_ptr);

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