#include <iostream>
#include "L101_022.h"

using namespace std;
int main() {
  int arr[] = {12, 4, 43, -3, 3, 8};
  int n = sizeof(arr) / sizeof(arr[0]);
  
  cout << "Ishodnyi massiv: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
    cout << endl;
  insertion_sort(arr, n);
  cout << "Sorted massiv: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
    cout << endl;
    return 0;
}