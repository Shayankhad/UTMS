#ifndef NOTFOUND_HPP
#define NOTFOUND_HPP
#include "global.hpp"
class NotFound : public MyException
{
public:
    NotFound() : MyException(NOT_FOUND) {}
};

#endif