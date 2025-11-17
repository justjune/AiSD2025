#include <iostream>
#include <string>
#include <vector>

#include "hash.h" 
#include "test.h"
using namespace std;


void test_hash_int() {
    vector<int> v = { 5, 2, 9, 1, 6 };

    cout << "Test 1 - index:" << hashFun(v) << endl;
    cout << "\n\n";
}

void test_hash_double() {
    vector<double> v = { 1.1, 3.3, 2.2, 4.4 };

    cout << "Test 1 - index:" << hashFun(v) << endl;
    cout << "\n\n";
}

void test_hash_string() {
    string s = "fvaefeavr";

    cout << "Test 1 - index:" << hashFun(s) << endl;
    cout << "\n\n";
}

void test_hash_char() {
    vector<char> v = { 'a', 'f', 't', 'j'};

    cout << "Test 1 - index:" << hashFun(v) << endl;
    cout << "\n\n";
}
