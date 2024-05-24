#include "global.hpp"
void extract_majors_csv(string address, vector<Major*> &majors){
    fstream file(address);
    if (!file.is_open()) {
        cerr << "failed to open the majors file!!!";
    }
    string line;
    getline (file , line);
    while(getline(file , line)){
        stringstream ss;
        ss << line;
        string id;
        getline(ss , id , ',');
        string major;
        getline(ss , major);
        Major* major_ptr = new Major;
        major_ptr->major_csv_setup(string_to_int(id) , major);
        majors.emplace_back(major_ptr);
    }
}