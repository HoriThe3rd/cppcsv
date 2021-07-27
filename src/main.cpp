// This is a main function for testing.
// Developer: Sansei Hori
// Since 3rd June 2019

#include <iostream>
#include <string>

#include "cppcsv.hpp"

using namespace std;

int main(void) {
    cout << "start." << endl;

    csv<float> data;
    try {
        data.load("rand_test.csv");
        cout << "col: " << data.get_colsize() << ", row: " << data.get_rowsize()
             << endl;
        // data.show();
    } catch (const std::runtime_error& e) {
        cout << "error!!!!: " << e.what() << endl;
    }
}