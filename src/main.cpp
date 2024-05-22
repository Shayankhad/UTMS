#include "global.hpp"

class Professors {
public:
    void x(){
        cout << PERMISSION_DENIED ;
    }
private:
    int pid;
    string name;
    int major_id;
    string position;
    string password;
};

class Student {
public:

private:
    int sid;
    string name;
    int major_id;
    int semester;
    string password;
};

int main (int argc , char* argv[]){
    cout << argc << endl;
    for(int i = 0 ; i < argc ; i++){
        cout << "argv[" << i << "]: " << argv[i] << endl;
    }    
    return 0;
}