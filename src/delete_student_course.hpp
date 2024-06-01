#ifndef DELETE_STUDENT_COURSE_HPP
#define DELETE_STUDENT_COURSE_HPP
#include "global.hpp"

void delete_student_course(string command , vector<Student *> &students ,  vector<Professor *> &professors , UtAccount *ut_account_ptr,int student_id);
#endif