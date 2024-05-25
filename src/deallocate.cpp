#include "global.hpp"

void deallocate(vector<Major *> &majors , vector<Student *> &students , vector<Course *> &courses ,vector<Professor *> &professors , UtAccount *ut_account_ptr )
{
    for (Major *major_ptr : majors)
    {
        delete major_ptr;
    }
    majors.clear();
    for (Student *student_ptr : students)
    {
        delete student_ptr;
    }
    students.clear();
    for (Professor *proffesor_ptr : professors)
    {
        delete proffesor_ptr;
    }
    professors.clear();
    for (Course *course_ptr : courses)
    {
        delete course_ptr;
    }
    courses.clear();

    delete ut_account_ptr;
}