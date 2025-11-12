#include "L0412_162.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    cout << "Тестирование быстрой сортировки\n" << endl;
    
    {
        vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
        cout << "До сортировки: \n";
        for (int x : arr) cout << x << " ";
        cout << endl;
        
        quicksort(span<int>(arr), 0, arr.size() - 1);
        
        cout << "После сортировки: \n";
        for (int x : arr) cout << x << " ";
        cout << endl;
        
        // Проверка
        vector<int> sorted = {1, 1, 2, 3, 4, 5, 6, 9};
        if (arr == sorted) 
        {
            cout << "Успех" << endl;
        } 
        else 
        {
            cout << "Провал" << endl;
        }
    }
}
