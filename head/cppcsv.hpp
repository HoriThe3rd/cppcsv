
#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

template <class T>
class csv{
    public:
        csv();
        bool load(const string& fileName, const int rows, const int cols, const bool header=true);
        void show() const;
        T operator()(const int row, const int col) const;

    private:
        vector<vector<T>> data;
        int row_size;
        int col_size;
        T stonum(const string str);
};

// --------- 以下実装 -------------

template <class T>
csv<T>::csv(){
    cout << "csv object is created." << endl;
}

// Load a csv file and store the data to STL vector.
// If the loading fails, this function returns "false".
template <class T>
bool csv<T>::load(const string& fileName, const int rows, const int cols, const bool header){
    // Open a csv file.
    ifstream file("fileName");
    if(!file){
        cout << "csv object can't load a file." << endl;
        return false;
    }

    // Save parameters
    row_size = rows;
    col_size = cols;

    // Initialize the data container.
    data.resize(rows);
    for(auto it : data) it.resize(cols);

    // Load the file.
    int row_cnt = 0;
    string loaded_str;
    while(getline(file, loaded_str)){
        int col_num = 0;
        string loaded_car;
        istringstream sstream(str);
        while(getline(sstream, tmp, ',')){
            data[row_cnt][col_cnt] = stonum(tmp);
            col_num++;
        }
        row_num++;
    }
    return true;
}

template <class T>
void csv<T>::show()const{
    for(int row_cnt=0; row_cnt<row_size; row_cnt++){
        for(int col_cnt=0; col_cnt<col_size; col_cnt++){
            cout << data[row_cnt][col_cnt] << " ";
        }
        cout << endl;
    }
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