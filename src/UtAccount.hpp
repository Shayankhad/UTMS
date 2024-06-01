#ifndef UTACCOUNT_HPP
#define UTACCOUNT_HPP
#include "global.hpp"

class UtAccount : public Uniperson
{
public:
    UtAccount()
    {
        id = 0;
        password = UT_ACCOUNT;
        name = UT_ACCOUNT;
    }
    void test_UtAccount()
    {
        cout << "id: " << id << endl;
        cout << "password: " << password << endl;
    }

private:
};

#endif
