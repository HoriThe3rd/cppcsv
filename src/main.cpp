// This is a main function for testing.
// Developer: Sansei Hori
// Since 3rd June 2019

#include "cppcsv.hpp"

int main(void){
    csv<int> w;
    w.load("test_w.csv", 5, 10);
    w.show();

    cout << "-----" << endl;
    for(int i=0; i<5; i++){
        for(int j=0; j<10; j++){
            cout << w(i,j) << " ";
        }
        cout << endl;
    }

    cout << "Finish" << endl;
}