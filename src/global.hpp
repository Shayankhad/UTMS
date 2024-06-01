#ifndef GLOBALL_HPP
#define GLOBALL_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <type_traits>

#define OK "OK"
#define EMPTY "Empty"
#define NOT_FOUND "Not Found"
#define BAD_REQUEST "Bad Request"
#define PERMISSION_DENIED "Permission Denied"
#define QUESTION_MARK "?"
#define GET "GET"
#define POST "POST"
#define DELETE "DELETE"
#define PUT "PUT"
#define LOGIN "login"
#define LOGOUT "logout"
#define ID "id"
#define PASSWORD "password"
#define COURSES "courses"
#define POST_SECOND_COMMAND "post"
#define TITLE "title"
#define MESSAGE "message"
#define POST_SECOND_COMMAND "post"
#define PERSONAL_PAGE "personal_page"
#define POST_ID "post_id"
#define CONNECT "connect"
#define NOTIFICATION "notification"
#define UT_ACCOUNT "UT_account"
#define COURSE_OFFER "course_offer"
#define COURSE_ID "course_id"
#define PROFESSOR_ID "professor_id"
#define CAPACITY "capacity"
#define TIME "time"
#define EXAM_DATE "exam_date"
#define CLASS_NUMBER "class_number"
#define MY_COURSES "my_courses"
#define NEW_POST "New Post"
#define NEW_COURSE_OFFERING "New Course Offering"
#define GET_COURSE "Get Course"
#define DELETE_COURSE "Delete Course"

using namespace std;

#include "string_to_int.hpp"
#include "check_number_type.hpp"
#include "MyException.hpp"
#include "OkExeption.hpp"
#include "Empty.hpp"
#include "NotFound.hpp"
#include "BadRequest.hpp"
#include "PermissionDenied.hpp"
#include "Post_system.hpp"
#include "Notif.hpp"
#include "Uniperson.hpp"
#include "UtAccount.hpp"
#include "Student.hpp"
#include "is_it_student.hpp"
#include "extract_students_csv.hpp"
#include "Professor.hpp"
#include "extract_professors_csv.hpp"
#include "check_id_match_in_peaple.hpp"
#include "identify_user.hpp"
#include "Course.hpp"
#include "extract_courses_csv.hpp"
#include "Major.hpp"
#include "extract_majors_csv.hpp"
#include "extract_csv.hpp"
#include "seperate_one_two_command.hpp"
#include "check_for_four_commands.hpp"
#include "check_for_second_commands.hpp"
#include "check_for_quastion_mark.hpp"
#include "login_setup.hpp"
#include "login_command.hpp"
#include "is_it_login_command.hpp"
#include "is_anyone_loged_in.hpp"
#include "is_it_logout_command.hpp"
#include "logout_command.hpp"
#include "is_it_connect_command.hpp"
#include "connect_command.hpp"
#include "check_for_double_quatation.hpp"
#include "is_it_post_command.hpp"
#include "post_command_setup.hpp"
#include "post_command.hpp"
#include "is_it_delete_post_command.hpp"
#include "check_post_id_exist.hpp"
#include "delete_post_command.hpp"
#include "is_it_notificaiton_command.hpp"
#include "notificaiton_command.hpp"
#include "add_notif_handeling.hpp"
#include "set_ut_account_ptr_contacts.hpp"
#include "PresentedCourse.hpp"
#include "find_PresentedCourse.hpp"
#include "how_many_courses_presented.hpp"
#include "set_arg_order.hpp"
#include "is_it_course_offer_command.hpp"
#include "check_course_id_match_in_courses.hpp"
#include "is_it_professor.hpp"
#include "seperate_day.hpp"
#include "seperate_hour.hpp"
#include "seperate_exam_date.hpp"
#include "course_offer_notif_handeling.hpp"
#include "check_course_offer_time_handeling.hpp"
#include "course_offer_command.hpp"
#include "is_it_show_presented_course_type_one_command.hpp"
#include "show_presented_course_type_one_command.hpp"
#include "is_it_show_presented_course_type_two_command.hpp"
#include "is_presented_course_id_exist.hpp"
#include "show_presented_course_type_two_command.hpp"
#include "is_it_take_course_command.hpp"
#include "check_take_course_time_handeling.hpp"
#include "take_course_command.hpp"
#include "is_it_delete_student_course.hpp"
#include "delete_student_course.hpp"
#include "deallocate.hpp"


// files/majors.csv
// files/students.csv
// files/courses.csv
// files/professors.csv
// files/majors.csv files/students.csv files/courses.csv files/professors.csv

// 810102566
// Shayan7812
#endif 


