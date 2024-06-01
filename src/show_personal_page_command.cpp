#include "global.hpp"
// show_my_posts
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
        ut_account_ptr->show_title_of_my_posts();
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
            student->show_title_of_my_posts();
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
            professor->show_title_of_my_posts();
        }
        
    }
    return 1;
}