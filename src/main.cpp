#include "global.hpp"

void run(vector<Student *> &students , vector<Professor *> professors , UtAccount *ut_account_ptr){
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
            if(is_it_login_command(command)){
                if(is_anyone_loged_in(students ,professors , ut_account_ptr)){
                    throw PermissionDenied();
                }
            }
            login_command(command ,students ,professors , ut_account_ptr);
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