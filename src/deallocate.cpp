#include "global.hpp"

void deallocate(vector<Major *> &majors, vector<Student *> &students, vector<Course *> &courses, vector<Professor *> &professors, UtAccount *ut_account_ptr, vector<PresentedCourse *> &presented_course)
{
    for (Major *major_ptr : majors)
    {
        delete major_ptr;
    }
    majors.clear();
    for (Student *student_ptr : students)
    {
        student_ptr->deallocate_uniperson();
        delete student_ptr;
    }
    students.clear();
    for (Professor *proffesor_ptr : professors)
    {
        proffesor_ptr->deallocate_uniperson();
        delete proffesor_ptr;
    }
    professors.clear();
    for (Course *course_ptr : courses)
    {
        delete course_ptr;
    }
    courses.clear();
    for (Course *course_ptr : courses)
    {
        delete course_ptr;
    }
    courses.clear();
    ut_account_ptr->deallocate_uniperson();
    delete ut_account_ptr;
    ut_account_ptr = nullptr;
    for (PresentedCourse *presented_course_ptr : presented_course)
    {
        delete presented_course_ptr;
    }
    presented_course.clear();
}