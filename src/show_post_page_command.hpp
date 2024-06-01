#ifndef SHOW_POST_PAGE_COMMAND_HPP
#define SHOW_POST_PAGE_COMMAND_HPP
#include "global.hpp"
int show_post_page_command(int user_id , int post_id ,vector<Student *> students
, vector<Professor *> professors , UtAccount *ut_account_ptr
, vector<PresentedCourse *> presented_course , vector<Major *> majors);
#endif
