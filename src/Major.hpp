#ifndef MAJOR_HPP
#define MAJOR_HPP
#include "global.hpp"

class Major
{
public:
    void major_csv_setup(int mid_, string major_)
    {
        mid = mid_;
        major = major_;
    }

    int get_mid()
    {
        return mid;
    }

    string get_major_name()
    {
        return major;
    }

private:
    int mid;
    string major;
};

#endif
