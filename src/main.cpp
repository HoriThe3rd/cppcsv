// This is a main function for testing.
// Developer: Sansei Hori
// Since 3rd June 2019

#include "cppcsv.hpp"

int main(void){
    csv<char> w;
    w.load("test_w.csv", 5, 10);
    w.show();
}