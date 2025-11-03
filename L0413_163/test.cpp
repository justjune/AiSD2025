#include <iostream>
#include <string>
#include <vector>

#include "partition.h" 
#include "test.h"
using namespace std;
 
void test_partition_int() {
    vector<int> intArray = { 1,2,3,4,5,6,7,8,9 };
    vector<int> arr1, arr2; 
    partition_vectors(intArray, 3, 5, arr1, arr2); 

    cout << "Test 1 - arr1: "; 
    for (int val : arr1) cout << val << " "; 
    cout << "\nTest 1 - arr2: ";
    for (int val : arr2) cout << val << " ";
    cout << "\n\n";
}

void test_partition_double() {
    vector<double> doubleArray = { 1.2, 0.3,5.6,4.,10.13 };
    vector<double> arr1, arr2;
    partition_vectors(doubleArray, 0, 1, arr1, arr2);

    cout << "Test 2 - arr1: ";
    for (double val : arr1) cout << val << " ";
    cout << "\nTest 2 - arr2: ";
    for (double val : arr2) cout << val << " ";
    cout << "\n\n";
}

void test_partition_string() {
    vector<string> strArray = { "abcd", "0.3", "hello", "lklk", "356" };
    vector<string> arr1, arr2;

    partition_vectors(strArray, 0, strArray.size() - 2, arr1, arr2);

    cout << "Test - arr1: ";
    for (const string& val : arr1) cout << val << " ";
    cout << "\nTest - arr2: ";
    for (const string& val : arr2) cout << val << " ";
    cout << "\n\n";
}