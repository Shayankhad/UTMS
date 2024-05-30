#include "global.hpp"

bool set_arg_order(vector<int> &arg_order , vector<vector<string>> arg_commands ){
    int turn = 1;
    
    if(turn == 1){
        for(vector<__cxx11::basic_string<char>>::size_type a = 0 ; a < arg_commands.size() ; a ++){
            if((arg_commands[a][0] == COURSE_ID) ){
                arg_order.push_back(a);
                turn ++;
                break;
            }
        }
    }
    if(turn == 2){
        for(vector<__cxx11::basic_string<char>>::size_type a = 0 ; a < arg_commands.size() ; a ++){
            if((arg_commands[a][0] == PROFESSOR_ID) ){
                arg_order.push_back(a);
                turn ++;
                break;
            }
        }
    }
    if(turn == 3){
        for(vector<__cxx11::basic_string<char>>::size_type a = 0 ; a < arg_commands.size() ; a ++){
            if((arg_commands[a][0] == CAPACITY) ){
                arg_order.push_back(a);
                turn ++;
                break;
            }
        }
    }
    if(turn == 4){
        for(vector<__cxx11::basic_string<char>>::size_type a = 0 ; a < arg_commands.size() ; a ++){
            if((arg_commands[a][0] == TIME) ){
                arg_order.push_back(a);
                turn ++;
                break;
            }
        }
    }
    if(turn == 5){
        for(vector<__cxx11::basic_string<char>>::size_type a = 0 ; a < arg_commands.size() ; a ++){
            if((arg_commands[a][0] == EXAM_DATE) ){
                arg_order.push_back(a);
                turn ++;
                break;
            }
        }
    }
    if(turn == 6){
        for(vector<__cxx11::basic_string<char>>::size_type a = 0 ; a < arg_commands.size() ; a ++){
            if((arg_commands[a][0] == CLASS_NUMBER) ){
                arg_order.push_back(a);
                turn ++;
                break;
            }
        }
    }
    if(turn == 7){
        return true;
    }
    
    return false;
}

bool is_it_course_offer_command(string command){
    /*
POST course_offer ? course_id 1 professor_id 810420432 capacity 70 time Sunday:13-15 exam_date 1403/4/4 class_number 2
POST course_offer ? course_id 1 professor_id 810420432 capacity 70 time Sunday:13-15 class_number 2 exam_date 1403/4/4
POST course_offer ? professor_id 810420432 course_id 1 capacity 70 time Sunday:13-15 exam_date 1403/4/4 class_number 2
    */
    vector<string> commands;
    stringstream ss;
    ss << command;
    string word;
    vector<vector<string>> arg_commands;
    int iteration = 0;
    while (getline(ss , word , ' ')){
        if ((!word.empty()) && (word != " ")) {
            commands.push_back(word);
            iteration ++;
        }
    }

    if(iteration != 15){
        return false;
    }

    for(vector<vector<__cxx11::basic_string<char>>>::size_type i = 3 ; i < 15 ; i = i +2 ){
        arg_commands.push_back({ commands[i] , commands[i + 1]});
    }

    vector<int> arg_order;
    set_arg_order(arg_order , arg_commands);
    for(int i = 0 ; i < arg_order.size() ; i++){
        cout << arg_order[i] << endl;
    }
    if(arg_order.size() != 6){
        return false;
    }

    // check_number_type


    return true;
}


void run(vector<Student *> &students , vector<Professor *> &professors , UtAccount *ut_account_ptr){
    set_ut_account_ptr_contacts(students ,professors , ut_account_ptr);
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
            check_for_quastion_mark(command);





            if(is_it_login_command(command)){
                if(is_anyone_loged_in(students ,professors , ut_account_ptr)){
                    throw PermissionDenied();
                }
                login_command(command ,students ,professors , ut_account_ptr);
            }






            if(is_it_logout_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                logout_command(students ,professors , ut_account_ptr);
            }






            if(is_it_connect_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                connect_command(command ,students ,professors , ut_account_ptr);
            }





            if(is_it_post_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                post_command(command ,students ,professors , ut_account_ptr);
            }





            if(is_it_delete_post_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                delete_post_command(command ,students ,professors , ut_account_ptr);
            }




            if(is_it_notificaiton_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                notificaiton_command(students ,professors , ut_account_ptr);
                continue;
            }




            cout << is_it_course_offer_command(command) << endl;



            // end
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
    vector<PresentedCourse *> presented_course;
    UtAccount *ut_account_ptr = new UtAccount();
    extract_majors_csv(argv[1], majors);
    extract_students_csv(argv[2], students);
    extract_courses_csv(argv[3], courses);
    extract_professors_csv(argv[4], professors);
    run(students ,professors , ut_account_ptr);
    deallocate(majors ,students , courses ,professors , ut_account_ptr ,presented_course );
    return 0;
}