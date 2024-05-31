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

string seperate_day(string time){
    // Sunday:13-15
    string day;
    stringstream ss;
    ss << time;
    getline(ss , day , ':' );
    return day;
}
vector<int> seperate_hour(string time){
    // Sunday:13-15
    string day;
    stringstream ss;
    ss << time;
    getline(ss , day , ':' );
    string start;
    getline(ss, start , '-');
    string finish;
    getline(ss, finish);
    vector<int> hour;
    hour.push_back(string_to_int(start));
    hour.push_back(string_to_int(finish));
    return hour;
}

vector<int> seperate_exam_date(string exam_date){
    // 1403/4/4
    vector<int> exam_date_vec;
    string day;
    string month;
    string year;
    stringstream ss;
    ss << exam_date;
    getline(ss, year , '/');
    getline(ss, month , '/');
    getline(ss, day);
    exam_date_vec.push_back(string_to_int(day));
    exam_date_vec.push_back(string_to_int(month));
    exam_date_vec.push_back(string_to_int(year));
    return exam_date_vec;
}



void course_offer_command(string command , vector<Student *> &students , vector<Course *> &courses, vector<Professor *> &professors , vector<PresentedCourse *> &presented_course , UtAccount *ut_account_ptr  ){
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
    int int_course_id = string_to_int(ordered_arg_commands[0][1]);
    int int_proffesor_id = string_to_int(ordered_arg_commands[1][1]);
    int int_capacity_id = string_to_int(ordered_arg_commands[2][1]);
    int int_class_number_id = string_to_int(ordered_arg_commands[5][1]);

    if(!check_course_id_match_in_courses(int_course_id , courses)){
        throw NotFound();
    }
    if(!check_id_match_in_peaple(int_proffesor_id , students , professors , ut_account_ptr)){
        throw NotFound();
    }
    if(!is_it_professor(int_proffesor_id , professors)){
        throw PermissionDenied();
    }
    for(auto & course : courses){
        if(course->get_id() == int_course_id){
            for(auto & professor : professors){
                if(professor->get_id() == int_proffesor_id){
                    if(!course->is_majors_id_match(professor->get_major_id())){
                        throw PermissionDenied();
                    }
                }
            }
        }  
    }

// ordered_arg_commands[0][0] = course_id
// ordered_arg_commands[1][0] = professor_id
// ordered_arg_commands[2][0] = capacity
// ordered_arg_commands[3][0] = time
// ordered_arg_commands[4][0] = exam_date
// ordered_arg_commands[5][0] = class_number
    vector<int> hour;
    string day = seperate_day(ordered_arg_commands[3][1]);
    hour = seperate_hour(ordered_arg_commands[3][1]);
    vector<int> exam_date_vec = seperate_exam_date(ordered_arg_commands[4][1]);

    PresentedCourse * presented_course_ptr = new PresentedCourse(int_course_id , int_proffesor_id , int_capacity_id ,day ,hour , exam_date_vec , int_class_number_id);
    presented_course.emplace_back(presented_course_ptr);
    throw OkExeption();
}

void run(vector<Student *> &students , vector<Course *> &courses, vector<Professor *> &professors , vector<PresentedCourse *> &presented_course , UtAccount *ut_account_ptr  ){
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
                course_offer_command(command , students , courses , professors , presented_course , ut_account_ptr);
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
    run(students , courses , professors , presented_course , ut_account_ptr);
    // for(auto & x : presented_course){
    //     x->test_show();
    // }

    for(auto & s : students){
        s->show_notif_vec();
    }
    deallocate(majors ,students , courses ,professors , ut_account_ptr ,presented_course );
    return 0;
}