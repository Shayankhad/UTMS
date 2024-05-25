#ifndef MYEXEPTION_HPP
#define MYEXEPTION_HPP
#include "global.hpp"
class MyException : public exception {
protected:
    string message;
public:
    MyException(const string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif