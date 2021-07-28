// This is a main function for testing.
// Developer: Sansei Hori
// Since 3rd June 2019

#include <iostream>
#include <string>

#include "cppcsv.hpp"

using namespace std;

int main(void) {
    cout << "start." << endl;

    // Test codes.
    csv<float> data;
    try {
        // load a file.
        data.load("test.csv");

        // test a getter for sizes.
        cout << "col: " << data.get_colsize() << ", row: " << data.get_rowsize()
             << endl;
        data.show();

        // test a getter as eigen
        Eigen::MatrixXf em = data.get_asEigen();
        cout << "---" << endl;
        cout << em << endl;

        // test () operator
        cout << "---" << endl;
        for (int i = 0; i < data.get_rowsize(); ++i) {
            for (int j = 0; j < data.get_colsize(); ++j) {
                cout << data(i, j) << ", " << flush;
            }
            cout << endl;
        }

        // test getter as vector 1d
        cout << "---" << endl;
        vector<float> v1 = data.get_asVector1d();
        for (auto& it : v1) {
            cout << it << ", ";
        }
        cout << endl;

        // test getter as vector 2d
        cout << "---" << endl;
        vector<vector<float>> v2 = data.get_asVector2d();
        for (int i = 0; i < v2.size(); ++i) {
            for (int j = 0; j < v2[i].size(); ++j) {
                cout << v2[i][j] << ", " << flush;
            }
            cout << endl;
        }
    } catch (const std::runtime_error& e) {
        cout << "error!!!!: " << e.what() << endl;
    }
}