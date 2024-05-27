#include "global.hpp"

int check_number_type(const string& str) {
    istringstream iss(str);
    long long int_value;
    float float_value;
    char remaining_char;

    if (iss >> int_value) {
        if (!(iss >> remaining_char)) {
            return 1;
        }
    }
    iss.clear();
    iss.str(str);
    if (iss >> float_value) {
        if (!(iss >> remaining_char)) {
            return 2;
        }
    }

    return 0;
}

bool check_id_match_in_peaple (int id ,vector<Student *> students, vector<Professor *> professors, UtAccount *ut_account_ptr ){
    for(auto & student : students){
        if(student->is_id_match(id)){
            return true;
        }
    }
    for(auto & professor : professors){
        if(professor->is_id_match(id)){
            return true;
        }
    }
    if(ut_account_ptr->is_id_match(id)){
        return true;
    }
    return false;
}

int identify_user(vector<Student *> students, vector<Professor *> professors, UtAccount *ut_account_ptr){
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
    if(!(check_number_type(commands[4]) == 1)){
        throw BadRequest();
    }
    int target_id = string_to_int(commands[4]);
    if(!(check_id_match_in_peaple(target_id ,students ,professors , ut_account_ptr))){
        throw NotFound();
    }
    if((iteration == 5) &&(commands[0] == POST) && (commands[1] == CONNECT) && (commands[3] == ID) ){
        for(auto &student : students){
            if((student->get_id() == target_id)){
                if(student->am_i_in_contact(user_id)){
                    throw BadRequest();
                }
                student->add_contacts(user_id);
            }
            if(student->get_id() == user_id){
                if(student->am_i_in_contact(target_id)){
                    throw BadRequest();
                }
                student->add_contacts(target_id);
            }
        }
        for(auto &professor : professors){
            if((professor->get_id() == target_id)){
                if(professor->am_i_in_contact(user_id)){
                    throw BadRequest();
                }
                professor->add_contacts(user_id);
            }
            if(professor->get_id() == user_id){
                if(professor->am_i_in_contact(target_id)){
                    throw BadRequest();
                }
                professor->add_contacts(target_id);
            }
        }
        if((ut_account_ptr->get_id() == target_id)){
            if(ut_account_ptr->am_i_in_contact(user_id)){
                throw BadRequest();
            }
            ut_account_ptr->add_contacts(user_id);
        }
        if(ut_account_ptr->get_id() == user_id){
            if(ut_account_ptr->am_i_in_contact(target_id)){
                throw BadRequest();
            }
            ut_account_ptr->add_contacts(target_id);
        }
        throw OkExeption();
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
    for(auto &professor : professors){
        professor->show_contacts();
    }
    deallocate(majors ,students , courses ,professors , ut_account_ptr );
    return 0;
}