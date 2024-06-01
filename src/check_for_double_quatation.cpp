#include "global.hpp"

bool check_for_double_quatation(string command)
{
    stringstream ss;
    ss << command;
    string command_1;
    getline(ss, command_1, ' ');
    string command_2;
    getline(ss, command_2, ' ');
    string question_mark;
    getline(ss, question_mark, ' ');
    string arg_1;
    getline(ss, arg_1, ' ');
    string arg_1_value;
    getline(ss, arg_1_value, '"');
    getline(ss, arg_1_value, '"');
    string arg_2;
    getline(ss, arg_2, ' ');
    getline(ss, arg_2, ' ');
    string test;
    if (getline(ss, test, '"'))
    {
        if (!(test == ""))
        {
            return false;
        }
    }
    string arg_2_value;
    int number_of_double_qoute = 0;
    while (getline(ss, arg_2_value, ' '))
    {
        for (char ch : arg_2_value)
        {
            if (ch == '"')
            {
                number_of_double_qoute++;
            }
        }
    }
    if (number_of_double_qoute == 0)
    {
        return false;
    }
    return true;
}