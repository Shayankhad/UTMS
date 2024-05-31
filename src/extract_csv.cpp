#include "global.hpp"

void extract_csv(vector<Major *> &majors ,vector<Student *> &students ,vector<Course *> &courses , vector<Professor *> &professors 
, string majors_address , string students_address , string courses_address , string professors_address )
{
    extract_majors_csv(majors_address, majors);
    extract_students_csv(students_address, students);
    extract_courses_csv(courses_address, courses);
    extract_professors_csv(professors_address, professors);
}