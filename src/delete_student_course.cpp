#include "global.hpp"

void delete_student_course(string command, vector<Student *> &students, vector<Professor *> &professors, UtAccount *ut_account_ptr, int student_id)
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
    if (string_to_int(commands[4]) <= 0)
    {
        throw BadRequest();
    }
    int target_course_id = 0;
    vector<int> token_courses;
    for (auto &student : students)
    {
        if (student->get_id() == student_id)
        {
            token_courses = student->get_token_courses();
        }
    }
    for (std::vector<int>::size_type i = 0; i < token_courses.size(); i++)
    {
        if (token_courses[i] == string_to_int(commands[4]))
        {
            target_course_id = string_to_int(commands[4]);
        }
    }
    if (target_course_id == 0)
    {
        throw NotFound();
    }

    for (auto &student : students)
    {
        if (student->get_id() == student_id)
        {
            student->delete_token_course(target_course_id);
        }
    }
    add_notif_handeling(students, professors, ut_account_ptr, DELETE_COURSE, student_id);
    throw OkExeption();
}
