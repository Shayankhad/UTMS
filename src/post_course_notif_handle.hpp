#ifndef POST_COURSE_NOTIF_HANDLE_HPP
#define POST_COURSE_NOTIF_HANDLE_HPP
#include "global.hpp"
void post_course_notif_handle(int user_id , int presented_course_id , string presented_course_name, vector<Student *> &students , vector<Professor *> &professors);
#endif