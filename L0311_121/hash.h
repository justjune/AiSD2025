#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept> 
#include <algorithm> 

using namespace std;


template <typename T>
long long hashFun(const vector<T>& v) {
    const long long P = 31;
    const long long M = 1'000'000'009;
    long long hash_value = 0;
    size_t n = v.size();

    // перемешивание индексов (сдвигаем начальную точку)
    int k = n / 2;
    for (size_t i = 0; i < n; ++i) {
        // индекс с циклическим сдвигом
        size_t idx = (i + k) % n;

        // преобразование элемента в int
        long long val = static_cast<long long>(v[idx]);

        hash_value = (hash_value * P + val) % M;
    }
    return hash_value;
}


long long hashFun(const string& s) {
    const long long P = 31;
    const long long M = 1'000'000'009;

    long long hash_value = 0;
    size_t n = s.length();
    int k = n / 2;
    string str = s;
    int char_code = 0;

    str = str.substr(n - k) + str.substr(0, n - k); // сдвиг для перемешивания символов
    for (char c : str) {
        char_code = static_cast<int> (c); // получаем код символа
        hash_value += (static_cast<long long>(hash_value) * P + char_code) % M;
    }
    return hash_value;
}
#endif