#ifndef EMPTY_HPP
#define EMPTY_HPP
#include "global.hpp"
class Empty : public MyException {
public:
    Empty() : MyException(EMPTY) {}
};

#endif