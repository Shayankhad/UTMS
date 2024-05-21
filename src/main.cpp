#include "global.hpp"

//a
int main (int argc , char* argv[]){
    cout << argc << endl;
    for(int i = 0 ; i < argc ; i++){
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }
    
    return 0;
}