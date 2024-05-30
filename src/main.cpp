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
    if(!set_arg_order(arg_order , arg_commands)){
        return false;
    }
    if(arg_order.size() != 6){
        return false;
    }
    return true;
}

bool check_course_id_match_in_courses(int course_id , vector<Course *> courses ){
    for(auto & course : courses){
        if(course->get_id() == course_id){
            return true;
        }
    }
    return false;
}

bool is_it_professor(int id , vector<Professor *> professors ){
    for(auto & professor : professors ){
        if(professor->get_id() == id){
            return true;
        }
    }
    return false;
}

void course_offer_command(string command , vector<Major *> &majors , vector<Student *> &students , vector<Course *> &courses, vector<Professor *> &professors , vector<PresentedCourse *> &presented_course , UtAccount *ut_account_ptr  ){
    vector<string> commands;
    stringstream ss;
    ss << command;
    string word;
    vector<vector<string>> arg_commands;
    while (getline(ss , word , ' ')){
        if ((!word.empty()) && (word != " ")) {
            commands.push_back(word);
        }
    }
    for(vector<vector<__cxx11::basic_string<char>>>::size_type i = 3 ; i < 15 ; i = i +2 ){
        arg_commands.push_back({ commands[i] , commands[i + 1]});
    }
    vector<int> arg_order;
    set_arg_order(arg_order , arg_commands);
    vector<vector<string>> ordered_arg_commands;
    for(std::vector<int>::size_type i = 0 ; i < arg_order.size() ; i++ ){
        ordered_arg_commands.push_back({arg_commands[arg_order[i]][0] , arg_commands[arg_order[i]][1] });
    }
// cout << ordered_arg_commands[0][0] << endl;
// cout << ordered_arg_commands[1][0] << endl;
// cout << ordered_arg_commands[2][0] << endl;
// cout << ordered_arg_commands[3][0] << endl;
// cout << ordered_arg_commands[4][0] << endl;
// cout << ordered_arg_commands[5][0] << endl;
// ordered_arg_commands[0][0] = course_id
// ordered_arg_commands[1][0] = professor_id
// ordered_arg_commands[2][0] = capacity
// ordered_arg_commands[3][0] = time
// ordered_arg_commands[4][0] = exam_date
// ordered_arg_commands[5][0] = class_number
    if((check_number_type(ordered_arg_commands[0][1]) != 1) ||
    (check_number_type(ordered_arg_commands[1][1]) != 1 ) ||
    (check_number_type(ordered_arg_commands[2][1]) != 1 ) ||
    (check_number_type(ordered_arg_commands[5][1]) != 1 ) ||
    (string_to_int(ordered_arg_commands[0][1]) <= 0) ||
    (string_to_int(ordered_arg_commands[1][1]) <= 0) ||
    (string_to_int(ordered_arg_commands[2][1]) <= 0) ||
    (string_to_int(ordered_arg_commands[5][1]) <= 0)){
        throw BadRequest();
    }

    if(!check_course_id_match_in_courses(string_to_int(ordered_arg_commands[0][1]) , courses)){
        throw NotFound();
    }
    if(!check_id_match_in_peaple(string_to_int(ordered_arg_commands[1][1]) , students , professors , ut_account_ptr)){
        throw NotFound();
    }
    if(!is_it_professor(string_to_int(ordered_arg_commands[1][1]) , professors)){
        throw PermissionDenied();
    }

    // proff id = string_to_int(ordered_arg_commands[1][1])
    // course_id = string_to_int(ordered_arg_commands[0][1])
    for(auto & course : courses){
        if(course->get_id() == string_to_int(ordered_arg_commands[0][1])){
            for(auto & professor : professors){
                if(professor->get_id() == string_to_int(ordered_arg_commands[1][1])){
                    if(!course->is_majors_id_match(professor->get_major_id())){
                        throw PermissionDenied();
                    }
                }
            }
        }  
    }

    
    throw OkExeption();
}

void run(vector<Major *> &majors , vector<Student *> &students , vector<Course *> &courses, vector<Professor *> &professors , vector<PresentedCourse *> &presented_course , UtAccount *ut_account_ptr  ){
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




            if(is_it_course_offer_command(command)){
                int user_id = identify_user(students ,professors , ut_account_ptr);
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                if(user_id != 0){
                    throw PermissionDenied();
                }
                course_offer_command(command , majors , students , courses , professors , presented_course , ut_account_ptr);
            }



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
    run(majors , students , courses , professors , presented_course , ut_account_ptr);
    deallocate(majors ,students , courses ,professors , ut_account_ptr ,presented_course );
    return 0;
}