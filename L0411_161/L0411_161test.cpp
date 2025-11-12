#include "L0411_161.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void test_merge_sorted_parts() 
{
    cout << "Test 1: Merge sorted parts: ";
    
    vector<int> arr = {1, 5, 3, 2, 6, 4};
    span<int> s(arr);
    
    merge_sort(s, 0, 5);
    
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
