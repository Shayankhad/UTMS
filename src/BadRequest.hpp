#ifndef BADREQUEST_HPP
#define BADREQUEST_HPP
#include "global.hpp"
class BadRequest : public MyException
{
public:
    BadRequest() : MyException(BAD_REQUEST) {}
};

#endif