#include <iostream>
#include <string>
#include <vector>

#include "binarySearch.h" 
#include "test.h"
using namespace std;

void test_binarySearch_int() {

    vector<int> v = { 5, 2, 9, 1, 6 };

    sort(v.begin(), v.end());

    size_t index = -1;
    binary_search(v, 6, 0, v.size() - 1, index);

    cout << "Test 1 - index:" << index << endl;
    cout << "\n\n";
};

void test_binarySearch_double() {

    vector<double> v = { 1.1, 3.3, 2.2, 4.4 };

    sort(v.begin(), v.end());
    size_t index = -1;
    binary_search(v, 3.3, 0, v.size() - 1, index);

    cout << "Test 1 - index:" << index << endl;
    cout << "\n\n";
};

void test_binarySearch_string() {

    vector<string> v = { "apple", "orange", "banana", "pear" };

    sort(v.begin(), v.end());
    size_t index = -1;
    binary_search(v, string("orange"), 0, v.size() - 1, index);

    cout << "Test 1 - index:" << index << endl;
    cout << "\n\n";
};