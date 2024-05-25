#ifndef PERMISION_DENIED_HPP
#define PERMISION_DENIED_HPP
#include "global.hpp"

class PermissionDenied : public MyException {
public:
    PermissionDenied() : MyException(PERMISSION_DENIED) {}
};

#endif