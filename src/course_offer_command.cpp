#include "global.hpp"

void course_offer_command(string command, vector<Student *> &students, vector<Course *> &courses, vector<Professor *> &professors, vector<PresentedCourse *> &presented_course, UtAccount *ut_account_ptr)
{
    vector<string> commands;
    stringstream ss;
    ss << command;
    string word;
    vector<vector<string>> arg_commands;
    while (getline(ss, word, ' '))
    {
        if ((!word.empty()) && (word != " "))
        {
            commands.push_back(word);
        }
    }
    for (vector<vector<__cxx11::basic_string<char>>>::size_type i = 3; i < 15; i = i + 2)
    {
        arg_commands.push_back({commands[i], commands[i + 1]});
    }
    vector<int> arg_order;
    set_arg_order(arg_order, arg_commands);
    vector<vector<string>> ordered_arg_commands;
    for (std::vector<int>::size_type i = 0; i < arg_order.size(); i++)
    {
        ordered_arg_commands.push_back({arg_commands[arg_order[i]][0], arg_commands[arg_order[i]][1]});
    }

    if ((check_number_type(ordered_arg_commands[0][1]) != 1) ||
        (check_number_type(ordered_arg_commands[1][1]) != 1) ||
        (check_number_type(ordered_arg_commands[2][1]) != 1) ||
        (check_number_type(ordered_arg_commands[5][1]) != 1) ||
        (string_to_int(ordered_arg_commands[0][1]) <= 0) ||
        (string_to_int(ordered_arg_commands[1][1]) <= 0) ||
        (string_to_int(ordered_arg_commands[2][1]) <= 0) ||
        (string_to_int(ordered_arg_commands[5][1]) <= 0))
    {
        throw BadRequest();
    }
    int int_course_id = string_to_int(ordered_arg_commands[0][1]);
    int int_proffesor_id = string_to_int(ordered_arg_commands[1][1]);
    int int_capacity_id = string_to_int(ordered_arg_commands[2][1]);
    int int_class_number_id = string_to_int(ordered_arg_commands[5][1]);

    if (!check_course_id_match_in_courses(int_course_id, courses))
    {
        throw NotFound();
    }
    if (!check_id_match_in_peaple(int_proffesor_id, students, professors, ut_account_ptr))
    {
        throw NotFound();
    }
    if (!is_it_professor(int_proffesor_id, professors))
    {
        throw PermissionDenied();
    }
    for (auto &course : courses)
    {
        if (course->get_id() == int_course_id)
        {
            for (auto &professor : professors)
            {
                if (professor->get_id() == int_proffesor_id)
                {
                    if (!course->is_majors_id_match(professor->get_major_id()))
                    {
                        throw PermissionDenied();
                    }
                }
            }
        }
    }

    vector<int> hour;
    string day = seperate_day(ordered_arg_commands[3][1]);
    hour = seperate_hour(ordered_arg_commands[3][1]);
    vector<int> exam_date_vec = seperate_exam_date(ordered_arg_commands[4][1]);
    check_course_offer_time_handeling(presented_course, hour, day, int_proffesor_id);
    int presented_course_id = how_many_courses_presented(presented_course);
    presented_course_id++;
    string course_name;
    for (auto &course : courses)
    {
        if (course->get_id() == int_course_id)
        {
            course_name = course->get_name();
        }
    }
    string professor_name;
    for (auto &professor : professors)
    {
        if (professor->get_id() == int_proffesor_id)
        {
            professor_name = professor->get_name();
        }
    }
    for (auto &professor : professors)
    {
        if (professor->get_id() == int_proffesor_id)
        {
            professor->add_token_courses(presented_course_id);
        }
    }
    int prerequisite;
    for (auto &course : courses)
    {
        if (course->get_id() == int_course_id)
        {
            prerequisite = course->get_prerequisite();
        }
    }
    PresentedCourse *presented_course_ptr = new PresentedCourse(int_course_id, course_name, int_proffesor_id, professor_name, int_capacity_id, day, hour, exam_date_vec, int_class_number_id, presented_course_id, prerequisite);
    presented_course.emplace_back(presented_course_ptr);
    course_offer_notif_handeling(students, professors, ut_account_ptr, int_proffesor_id);
    throw OkExeption();
}