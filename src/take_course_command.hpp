#ifndef TAKE_COURSE_COMMAND_HPP
#define TAKE_COURSE_COMMAND_HPP
#include "global.hpp"

void take_course_command(string command, vector<Student *> &students, vector<Course *> &courses, vector<Professor *> &professors, vector<PresentedCourse *> &presented_course, UtAccount *ut_account_ptr, int student_id);
#endif