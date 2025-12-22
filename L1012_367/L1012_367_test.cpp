//Попов Николай, ПМ-201, Восхождение по холму , L1012_367
#include "L1012_367.hpp"
#include <iostream>

using namespace std;

int main(){
    cout << "\nТест 1: Обе строки нормальные" << endl;
    char s[] = "ABCD";
    char t[] = "XYZ";
    int i, j;
    
    goal_cell(s, t, &i, &j);
    cout << "s='ABCD'(4), t='XYZ'(3) -> i=" << i << ", j=" << j << endl;
    
    if(i == 3 && j == 2) {
        cout << "OK" << endl;
    } else {
        cout << "FAIL" << endl;
    }

    cout << "\nТест 2: Одна пустая" << endl;
    char s[] = "ABCD";
    char t[] = "";
    int i, j;
    
    goal_cell(s, t, &i, &j);
    cout << "s='ABCD'(4), t=''(3) -> i=" << i << ", j=" << j << endl;
    
    if(i == 3 && j == -1) {
        cout << "OK" << endl;
    } else {
        cout << "FAIL" << endl;
    }

    cout << "\nТест 3: Обе строки пустые" << endl;
    char s[] = "";
    char t[] = "";
    int i, j;
    
    goal_cell(s, t, &i, &j);
    cout << "s=''(4), t=''(3) -> i=" << i << ", j=" << j << endl;
    
    if(i == -1 && j == -1) {
        cout << "OK" << endl;
    } else {
        cout << "FAIL" << endl;
    }
}