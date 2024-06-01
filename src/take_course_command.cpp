#include "global.hpp"

void take_course_command(string command, vector<Student *> &students, vector<Course *> &courses, vector<Professor *> &professors, vector<PresentedCourse *> &presented_course, UtAccount *ut_account_ptr, int student_id)
{
    vector<string> commands;
    stringstream ss;
    ss << command;
    string word;
    while (getline(ss, word, ' '))
    {
        if (!(word == ""))
        {
            commands.push_back(word);
        }
    }

    if (check_number_type(commands[4]) != 1)
    {
        throw BadRequest();
    }

    int target_presented_course_id = string_to_int(commands[4]);
    if (target_presented_course_id <= 0)
    {
        throw BadRequest();
    }
    bool check_id_exist = false;
    for (auto &presented_c : presented_course)
    {
        if (presented_c->is_presented_course_match(target_presented_course_id))
        {
            check_id_exist = true;
        }
    }
    if (!check_id_exist)
    {
        throw NotFound();
    }

    PresentedCourse *presented_c_ptr = find_PresentedCourse(target_presented_course_id, presented_course);
    for (auto &student : students)
    {
        if (student->get_id() == student_id)
        {
            if (!presented_c_ptr->check_semester(student->get_semester()))
            {
                throw PermissionDenied();
            }
        }
    }
    int course_id = presented_c_ptr->get_course_id();
    int student_major_id;
    for (auto &student : students)
    {
        if (student->get_id() == student_id)
        {
            student_major_id = student->get_major_id();
        }
    }

    for (auto &student : students)
    {
        if (student->get_id() == student_id)
        {
            for (auto &course : courses)
            {
                if (course->get_id() == course_id)
                {
                    if (!course->is_majors_id_match(student_major_id))
                    {
                        throw PermissionDenied();
                    }
                }
            }
        }
    }

    check_take_course_time_handeling(student_id, students, target_presented_course_id, presented_course);

    for (auto &student : students)
    {
        if (student->get_id() == student_id)
        {
            student->add_token_courses(target_presented_course_id);
        }
    }
    add_notif_handeling(students, professors, ut_account_ptr, GET_COURSE, student_id);
    throw OkExeption();
}