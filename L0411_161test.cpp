#include "L0411_161.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void test_merge_sorted_parts() 
{
    cout << "Test 1: Merge sorted parts: ";
    
    vector<int> arr = {1, 3, 5, 2, 4, 6};
    span<int> s(arr);
    
    merge(s, 0, 2, 5);
    
    vector<int> expect = {1, 2, 3, 4, 5, 6};
    if (arr == expect) 
    {
        cout << "Верно\n";
    } 
    else 
    {
        cout << "Провал\n";
        cout << "Програмное ожидание: ";
        for (auto x : expect) cout << x << " ";
        cout << "\nGot: ";
        for (auto x : arr) cout << x << " ";
        cout << "\n";
    }
}

int main() 
{
    cout << "Проверяем тесты\n\n";
    
    test_merge_sorted_parts();
    
    cout << "\nТесты завершены!\n";
    return 0;
}
