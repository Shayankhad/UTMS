#ifndef UTACCOUNT_HPP
#define UTACCOUNT_HPP
#include "global.hpp"

class UtAccount : public Uniperson{
public:
    UtAccount(){
        id = 0;
        string password  = UT_ACCOUNT;
    }
private:
};

#endif
