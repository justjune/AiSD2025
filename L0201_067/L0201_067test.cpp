//Тесты для листинга 2.1, Чистяков Андрей, ПМ-201
#include "L0201_067.HPP"
#include <iostream>
#include <list>
using namespace std;
int main() {
    list <string> numbers = { "z","gaf", "gaf", "aaaaaaa", "bbbb" };

    selection_sort(begin(numbers), end(numbers));

    for (string num : numbers) {
        cout << num << " ";
    }

    return 0;
}