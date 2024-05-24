#ifndef MAJOR_HPP
#define MAJOR_HPP
#include "global.hpp"

class Major {
public:
    void major_csv_setup(int mid_ , string major_){
        mid = mid_;
        major = major_;
    }
    void test_show(){
        cout << "mid: " << mid << endl;
        cout << "major: "<< major << endl;
    }
private:
    int mid;
    string major;
};

#endif
