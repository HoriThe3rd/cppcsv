// This is a main function for testing.
// Developer: Sansei Hori
// Since 3rd June 2019

#include "cppcsv.hpp"
#include <string>
#include <iostream>

using namespace std;

int main(void){
    cout << "start." << endl;

    csv<int> w;
    w.load("test.csv", 3, 4);
    w.show();
    
    cout << "done." << endl;
}