#ifndef OKEXEPTION_HPP
#define OKEXEPTION_HPP
#include "global.hpp"
class OkExeption : public MyException {
public:
    OkExeption() : MyException(OK) {}
};

#endif