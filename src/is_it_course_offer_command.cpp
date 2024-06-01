#include "global.hpp"

bool is_it_course_offer_command(string command)
{

    vector<string> commands;
    stringstream ss;
    ss << command;
    string word;
    vector<vector<string>> arg_commands;
    int iteration = 0;
    while (getline(ss, word, ' '))
    {
        if ((!word.empty()) && (word != " "))
        {
            commands.push_back(word);
            iteration++;
        }
    }
    if (iteration != 15)
    {
        return false;
    }
    for (vector<vector<__cxx11::basic_string<char>>>::size_type i = 3; i < 15; i = i + 2)
    {
        arg_commands.push_back({commands[i], commands[i + 1]});
    }
    vector<int> arg_order;
    if (!set_arg_order(arg_order, arg_commands))
    {
        return false;
    }
    if (arg_order.size() != 6)
    {
        return false;
    }
    return true;
}