// This is a main function for testing.
// Developer: Sansei Hori
// Since 3rd June 2019

#include "cppcsv.hpp"

int main(void){
    csv<int> w;
    w.load("test_w.csv", 5, 10);
    w.show();

    cout << "-------" << endl;
    csv<int> w2("test_w.csv", 5, 10);
    w2.show();

    cout << "Finish" << endl;
}