
#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

template <class T>
class csv{
    public:
        csv();
        bool load(const string& fileName, const int rows, const int cols);
        void show() const;
        const int get_rowsize() const;
        const int get_colsize() const;
        T operator()(const int row, const int col) const;

    private:
        vector<vector<T>> data;
        int row_size;
        int col_size;
        T stonum(const string str);
        bool has_data;
};

template <class T>
csv<T>::csv():
    has_data(false) {
    cout << "csv object is created." << endl;
}

// Load a csv file and store the data to STL vector.
// If the loading fails, this function returns "false".
template <class T>
bool csv<T>::load(const string& fileName, const int rows, const int cols){
    // Open a csv file.
    ifstream file(fileName);
    if(!file){
        cout << "csv object can't open a file." << endl;
        return false;
    }

    // Save parameters
    row_size = rows;
    col_size = cols;

    // Initialize the data container.
    data.resize(rows);
    for (int i=0; i<rows; i++){
        data[i].resize(cols);
    }

    // Load the file.
    int row_num = 0;
    string loaded_str;
    while(getline(file, loaded_str)){
        int col_num = 0;
        string tmp;
        istringstream sstream(loaded_str);
        while(getline(sstream, tmp, ',')){
            data[row_num][col_num] = stonum(tmp);
            col_num++;
        }
        row_num++;
    }
    has_data = true;
    return true;
}

template <class T>
void csv<T>::show()const{
    // Check the access to the data without loading csv.
    if(!has_data){
        cout << "csv object doesn't have a data." << endl;
        exit(0);
    }
    // Display data
    for(int row_cnt=0; row_cnt<row_size; row_cnt++){
        for(int col_cnt=0; col_cnt<col_size; col_cnt++){
            cout << data[row_cnt][col_cnt] << " ";
        }
        cout << endl;
    }
}

// Getters
template <class T>
const int csv<T>::get_rowsize() const{ return row_size; }

template <class T>
const int csv<T>::get_colsize() const{ return col_size; }

template <class T>
T csv<T>::operator()(const int row, const int col) const{
    if(!has_data){
        cout << "csv object doesn't have a data." << endl;
        exit(0);
    }
    return data[row][col];
}

// String to number converters.
template <class T>
inline T csv<T>::stonum(const string str){
    return stoi(str);
}

template <>
inline double csv<double>::stonum(const string str){
    return stod(str);
}

template <>
inline float csv<float>::stonum(const string str){
    return stof(str);
}