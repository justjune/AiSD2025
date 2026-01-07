#ifndef L0101_026_HPP
#define L0101_026_HPP
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
template<typename Iterator>
void insertion_sort(Iterator first, Iterator last)
{
    if (first == last) return; // пустой контейнер

    for (Iterator i = next(first); i != last; ++i) {
        Iterator j = i;
        Iterator k = prev(i);

        while (j != first && *j < *k) {
            iter_swap(j, k);
            --j;
            if (j != first) --k;
        }
    }
}
#endif