#ifndef TA_FORM_COMMAND_HPP
#define TA_FORM_COMMAND_HPP
#include "global.hpp"
void ta_form_command(string command , int user_id , vector<Student *> &students , vector<Professor *> &professors , UtAccount *ut_account_ptr , vector<PresentedCourse *> &presented_course);
#endif