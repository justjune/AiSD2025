#ifndef PARTITION_H
#define PARTITION_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept> 
#include <algorithm> 

#include "partition.h" 

using namespace std;

template <typename T>
void partition_vectors(const vector<T>& arr, size_t l, size_t h, 
    vector<T>& arr1, vector<T>& arr2) {  

    size_t n = arr.size();

    if (l > h || h >= n) 
        throw out_of_range("Некорректные границы");
    

    size_t n1 = h - l + 1;
    size_t n2 = n - n1;

    // очищаем вектора
    arr1.clear();
    arr2.clear();

    // изменяем размер выходных векторов
    arr1.resize(n1);
    arr2.resize(n2);

    for (size_t i = 0; i < n1; i++) {
        arr1[i] = arr[l + i];
    }

    // заполняем второй вектор сначала до l потом после h+1
    size_t arr2_index = 0;
    for (size_t i = 0; i < l; i++) {
        arr2[arr2_index++] = arr[i];
    }
    for (size_t i = h + 1; i < n; i++) {
        arr2[arr2_index++] = arr[i];
    }
}
#endif