// This is a main function for testing.
// Developer: Sansei Hori
// Since 3rd June 2019

#include "cppcsv.hpp"
#include <string>
#include <iostream>

using namespace std;

int main(void){
    csv<int> w;
    w.load("test2.csv", 3, 5);
    
    vector<vector<int>> v2;
    v2 = w.get_asVector2d();

    for(int i=0; i<3; i++){
        for(int j=0; j<5; j++){
            cout << v2[i][j] << ", ";
        }
        cout << endl;
    }
}