#include "global.hpp"

int check_number_type(const string &str)
{
    istringstream iss(str);
    long long int_value;
    float float_value;
    char remaining_char;

    if (iss >> int_value)
    {
        if (!(iss >> remaining_char))
        {
            return 1;
        }
    }
    iss.clear();
    iss.str(str);
    if (iss >> float_value)
    {
        if (!(iss >> remaining_char))
        {
            return 2;
        }
    }

    return 0;
}