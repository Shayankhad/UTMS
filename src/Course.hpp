#ifndef COURSE_HPP
#define COURSE_HPP
#include "global.hpp"

class Course {
public:

private:
    int cid;
    string name;
    int credit;
    int prerequisite;
    vector<int> majors_id;
};

#endif
