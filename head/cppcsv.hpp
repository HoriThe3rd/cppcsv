
#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Eigen/Core"
#include "Eigen/Geometry"

using namespace std;

template <class T>
class csv {
   public:
    csv();
    csv(const string& fileName);
    bool load(const string& fileName);
    void show() const;
    const int get_rowsize() const;
    const int get_colsize() const;
    T operator()(const int row, const int col) const;
    void set_from_eigen(
        Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> em);  // dev.
    const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> get_asEigen() const;
    vector<T> get_asVector1d() const;
    vector<vector<T>> get_asVector2d() const;

   private:
    vector<vector<T>> data;
    int row_size;
    int col_size;
    T stonum(const string str);
};

template <class T>
csv<T>::csv() {}

template <class T>
csv<T>::csv(const string& fileName) {
    load(fileName);
}

// Load a csv file without the row size and col size.
template <class T>
bool csv<T>::load(const string& fileName) {
    ifstream file(fileName);
    if (file.fail()) throw runtime_error("csv object can't open a file.");

    // Buffers
    string str_buf, elm;
    vector<T> line_buf;
    // Load and separate by comma.
    while (getline(file, str_buf)) {
        istringstream sstream(str_buf);
        while (getline(sstream, elm, ',')) {
            line_buf.push_back(stonum(elm));
        }
        data.push_back(line_buf);
        line_buf.clear();
    }
    // Set data size parameters.
    row_size = data.size();
    col_size = data[0].size();
    return true;
}

template <class T>
void csv<T>::show() const {
    // Check the access to the data without loading csv.
    if (data.empty()) throw runtime_error("csv object doesn't have a data.");

    // Python like display
    cout << "[";
    for (int row_cnt = 0; row_cnt < row_size; row_cnt++) {
        if (row_cnt != 0) cout << " ";
        cout << "[";
        for (int col_cnt = 0; col_cnt < col_size; col_cnt++) {
            cout << data[row_cnt][col_cnt];
            if (col_cnt < col_size - 1) cout << ",\t";
        }
        cout << "]";
        if (row_cnt < row_size - 1) cout << ", " << endl;
    }
    cout << "]" << endl;
}

// ======== Setters ==========
template <class T>
void csv<T>::set_from_eigen(
    Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> em) {
    if (data.empty() == false) data.clear();
    // Resize the data container if the source matrix size is not same as the
    // container.
    if (em.rows() != row_size || em.cols() != col_size) {
        data.resize(em.rows());
        for (int i = 0; i < em.rows(); i++) {
            data[i].resize(em.cols());
        }
    }

    // Move the values from the source matrix to the destination container.
    for (int i = 0; i < em.rows(); i++) {
        for (int j = 0; j < em.cols(); j++) {
            data[i][j] = em(i, j);
        }
    }
}

// ==== Getters ====
template <class T>
const int csv<T>::get_rowsize() const {
    return row_size;
}

template <class T>
const int csv<T>::get_colsize() const {
    return col_size;
}

// You can access each elements of the csv by obj(row, col).
// "at" method can throw an exception when invalid row and col.
template <class T>
T csv<T>::operator()(const int row, const int col) const {
    if (data.empty()) throw runtime_error("csv object doesn't have a data.");
    return data.at(row).at(col);
}

// You can get all elements of the csv as Eigen matrix format.
template <class T>
const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> csv<T>::get_asEigen()
    const {
    // Confirm the existence of the data.
    if (data.empty()) throw runtime_error("csv object doesn't have a data.");

    // Initialize an Eigen matrix.
    Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> mat =
        Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>::Zero(row_size,
                                                               col_size);

    // Copy the data to the Eigen matrix from the STL vector.
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            mat(i, j) = data[i][j];
        }
    }
    return mat;
}

// Return data as 1 dimension std::vector.
template <class T>
vector<T> csv<T>::get_asVector1d() const {
    // dev!!!
    vector<T> v;
    for (int r = 0; r < row_size; r++) {
        for (int c = 0; c < col_size; c++) {
            v.push_back(data[r][c]);
        }
    }
    return v;
}

// Return data as 2 dimension std::vector.
template <class T>
vector<vector<T>> csv<T>::get_asVector2d() const {
    return data;
}

// ======== Private functions ==========

// String to number converters.
template <class T>
inline T csv<T>::stonum(const string str) {
    throw invalid_argument(
        "csv object: You choose invalid argument type. I can read int, double, "
        "and float type only.");
}

template <>
inline int csv<int>::stonum(string str) {
    return stoi(str);
}

template <>
inline double csv<double>::stonum(const string str) {
    return stod(str);
}

template <>
inline float csv<float>::stonum(const string str) {
    return stof(str);
}