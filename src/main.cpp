#include "global.hpp"


int main (int argc , char* argv[]){
    argc++;
    argc--;
    vector<Major*> majors;
    extract_majors_csv(argv[1] , majors);
    for (auto & x : majors){
        x->test_show();
    }
}