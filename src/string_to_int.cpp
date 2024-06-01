#include "global.hpp"

int string_to_int(string str)
{
    int num;
    stringstream ss(str);
    ss >> num;
    return num;
}