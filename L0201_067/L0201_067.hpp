#ifndef L0201_067_HPP
#define L0201_067_HPP
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
template<typename Iterator>
void selection_sort(Iterator first, Iterator last) {
    if (first == last) return; // пустой контейнер

    for (Iterator i = first; i != last; ++i) {
        Iterator min = i;
        Iterator j = i;
        ++j; // j = i + 1

        for (; j != last; ++j) {
            if (*j < *min) {
                min = j;
            }
        }

        // Обмен элементов
        if (min != i) {
            iter_swap(i, min);
        }
    }
}
#endif