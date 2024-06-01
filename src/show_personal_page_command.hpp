#ifndef SHOW_PERSONAL_PAGE_COMMAND_HPP
#define SHOW_PERSONAL_PAGE_COMMAND_HPP
#include "global.hpp"
int show_personal_page_command(string command, vector<Student *> students, vector<Professor *> professors, UtAccount *ut_account_ptr, vector<PresentedCourse *> presented_course, vector<Major *> majors);
#endif