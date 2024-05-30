#ifndef COURSE_HPP
#define COURSE_HPP
#include "global.hpp"

class Course {
public:
    void course_csv_setup(int cid_ , string name_ , int credit_ , int prerequisite_ , vector<int> majors_id_ ){
        cid = cid_;
        name = name_;
        credit = credit_;
        prerequisite = prerequisite_;
        majors_id = majors_id_;
    }
    void test_show(){
        cout << "cid: " << cid << endl;
        cout << "name: " << name << endl;
        cout << "credit: " << credit << endl;
        cout << "prerequisite: " << prerequisite << endl;
        cout << "majors_id(s): ";
        for(vector<int>::size_type i = 0 ; i < majors_id.size() ; i++){
            cout << majors_id[i] << " ";
        }
        cout << endl;
    }

    int get_id(){
        return cid;
    }
private:
    int cid;
    string name;
    int credit;
    int prerequisite;
    vector<int> majors_id;
};

#endif
