#ifndef COURSE_OFFER_COMMAND_HPP
#define COURSE_OFFER_COMMAND_HPP
#include "global.hpp"
void course_offer_command(string command, vector<Student *> &students, vector<Course *> &courses, vector<Professor *> &professors, vector<PresentedCourse *> &presented_course, UtAccount *ut_account_ptr);
#endif