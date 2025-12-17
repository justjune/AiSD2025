//Тесты для листинга 1.1, Чистяков Андрей, ПМ-201
#include <iostream>
#include "L0101_026.HPP"
#include <list>
using namespace std;
int main() {
    list <string> numbers = { "z","gaf", "gaf", "aaaaaaa", "bbbb"};

    insertion_sort(begin(numbers), end(numbers));

    for (string num : numbers) {
        cout << num << " ";
    }

    return 0;
}