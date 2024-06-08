#include "global.hpp"

int main(int argc, char *argv[])
{
    argc++;
    argc--;
    vector<Major *> majors;
    vector<Student *> students;
    vector<Course *> courses;
    vector<Professor *> professors;
    vector<PresentedCourse *> presented_course;
    UtAccount *ut_account_ptr = new UtAccount();
    extract_csv(majors, students, courses, professors, argv[1], argv[2], argv[3], argv[4]);
    interface(students, courses, professors, presented_course, ut_account_ptr, majors);
    deallocate(majors, students, courses, professors, ut_account_ptr, presented_course);
    return 0;
}