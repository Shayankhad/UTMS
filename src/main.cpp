#include "global.hpp"

bool is_it_show_personal_page_command(string command){
    vector<string> commands;
    stringstream ss;
    ss << command;
    string word;
    int iteration = 0 ;
    while (getline(ss, word, ' '))
    {
        if(!(word == "" )){
            commands.push_back(word);
            iteration ++;
        }
    }
    if(iteration == 5){
        if((commands[0] == GET) && (commands[1] == PERSONAL_PAGE) && (commands[3] == ID)){
            return true;
        }else {
            return false;
        }
    }else {
        return false;
    }
}


int show_personal_page_command(string command ,vector<Student *> students
, vector<Professor *> professors , UtAccount *ut_account_ptr
, vector<PresentedCourse *> presented_course , vector<Major *> majors){
    vector<string> commands;
    stringstream ss;
    ss << command;
    string word;
    while (getline(ss, word, ' '))
    {
        if(!(word == "" )){
            commands.push_back(word);
        }
    }

    if(check_number_type(commands[4]) != 1){
        throw BadRequest();
    }
    int target_id = string_to_int(commands[4]);
    if(target_id < 0){
        throw BadRequest();
    }

    if(!check_id_match_in_peaple(target_id , students , professors , ut_account_ptr)){
        throw NotFound();
    }


    int type_person = 0;
    if(is_it_student(target_id , students)){
        type_person = 1;
    }
    if(is_it_professor(target_id , professors)){
        type_person = 2;
    }
    if(is_it_ut_account(target_id)){
        type_person = 3;
    }
    if(type_person == 0){
        throw NotFound();
    }
    if(type_person == 3){
        cout << UT_ACCOUNT << endl;
        ut_account_ptr->show_my_posts();
        return 1;
    }
    if(type_person == 1){
        string student_name;
        int major_id;
        string major_name;
        int semester;
        vector<int> token_courses;
        for(auto & student : students ){
            if(student->get_id() == target_id){
                student_name = student->get_name();
                major_id = student->get_major_id();
                semester = student->get_semester();
                token_courses = student->get_token_courses();
                for(auto & major : majors){
                    if(major->get_mid() == major_id){
                        major_name = major->get_major_name();
                    }
                }
            }
        }
        
        cout << student_name << " " << major_name << " " << semester;

        if(token_courses.size() == 0){
            cout << endl;
        }
        if(token_courses.size() == 1){
            PresentedCourse * presented_course_ptr = find_PresentedCourse(token_courses[0] , presented_course);
            cout << " " << presented_course_ptr->get_course_name() << endl;
        }
        if(token_courses.size() > 1){
            cout << " ";
            for(std::vector<int>::size_type i = 0 ; i < token_courses.size() ; i++){
                if( i == token_courses.size() - 1){
                    PresentedCourse * presented_course_ptr = find_PresentedCourse(token_courses[i] , presented_course);
                    cout << presented_course_ptr->get_course_name() << endl;
                }else{
                    PresentedCourse * presented_course_ptr = find_PresentedCourse(token_courses[i] , presented_course);
                    cout << presented_course_ptr->get_course_name() <<",";
                }
            }
        }
        for(auto & student : students){
            student->show_my_posts();
        }
        return 1;
    }

    if(type_person == 2){
        string proffesor_name;
        int major_id;
        string major_name;
        string position;
        vector<int> token_courses;
        for(auto & professor : professors ){
            if(professor->get_id() == target_id){
                proffesor_name = professor->get_name();
                major_id = professor->get_major_id();
                position = professor->get_position();
                token_courses = professor->get_token_courses();
                for(auto & major : majors){
                    if(major->get_mid() == major_id){
                        major_name = major->get_major_name();
                    }
                }
            }
        }
        
        cout << proffesor_name << " " << major_name << " " << position;

        if(token_courses.size() == 0){
            cout << endl;
        }
        if(token_courses.size() == 1){
            PresentedCourse * presented_course_ptr = find_PresentedCourse(token_courses[0] , presented_course);
            cout << " " << presented_course_ptr->get_course_name() << endl;
        }
        if(token_courses.size() > 1){
            cout << " ";
            for(std::vector<int>::size_type i = 0 ; i < token_courses.size() ; i++){
                if( i == token_courses.size() - 1){
                    PresentedCourse * presented_course_ptr = find_PresentedCourse(token_courses[i] , presented_course);
                    cout << presented_course_ptr->get_course_name() << endl;
                }else{
                    PresentedCourse * presented_course_ptr = find_PresentedCourse(token_courses[i] , presented_course);
                    cout << presented_course_ptr->get_course_name() <<",";
                }
            }
        }
        for(auto & professor : professors){
            professor->show_my_posts();
        }
        
    }
    return 1;
}


void run(vector<Student *> &students , vector<Course *> &courses, vector<Professor *> &professors , vector<PresentedCourse *> &presented_course , UtAccount *ut_account_ptr , vector<Major *> &majors ){
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
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                int user_id = identify_user(students ,professors , ut_account_ptr);
                if(user_id != 0){
                    throw PermissionDenied();
                }
                course_offer_command(command , students , courses , professors , presented_course , ut_account_ptr);
            }





            if(is_it_show_presented_course_type_one_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                show_presented_course_type_one_command(presented_course);
                continue;
            }




            if(is_it_show_presented_course_type_two_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                show_presented_course_type_two_command( command , presented_course);
                continue;
            }




            if(is_it_take_course_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                int user_id = identify_user(students ,professors , ut_account_ptr);
                if(!is_it_student(user_id , students)){
                    throw PermissionDenied();
                }
                take_course_command(command ,students , courses , professors , presented_course , ut_account_ptr , user_id );
            }







            if(is_it_delete_student_course(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                int user_id = identify_user(students ,professors , ut_account_ptr);
                if(!is_it_student(user_id , students)){
                    throw PermissionDenied();
                }
                delete_student_course(command , students , professors , ut_account_ptr , user_id);
            }





            if(is_it_show_my_courses_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                int user_id = identify_user(students ,professors , ut_account_ptr);
                if(!is_it_student(user_id , students)){
                    throw PermissionDenied();
                }
                show_my_courses_command(user_id , students , presented_course);
                continue;
            }







            if(is_it_show_personal_page_command(command)){
                if(!(is_anyone_loged_in(students ,professors , ut_account_ptr))){
                    throw PermissionDenied();
                }
                show_personal_page_command(command , students , professors , ut_account_ptr  , presented_course , majors  );
                continue;
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
    extract_csv(majors , students , courses , professors , argv[1] , argv[2] , argv[3] , argv[4]);
    run(students , courses , professors , presented_course , ut_account_ptr ,majors);
    deallocate(majors ,students , courses ,professors , ut_account_ptr ,presented_course );
    return 0;
}