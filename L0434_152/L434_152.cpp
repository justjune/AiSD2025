#include "L434_152.hpp"
#include <iostream>
#include <vector>
void demo_pyramid()
{
    PriorityQueue<int> pq;
    PriorityQueue<int> fast_test;
    vector<int> vec = { 4, 5, 7, 5, 2, 1 };
    fast_test.make_heap_fast(vec);
    fast_test.print();

    int i = pq.heap_compare(3, 6, 12);
    cout << "\nheap compare k = " << i << '\n';
    vector<int> numbers = { 3, 1, 4, 1, 5, 9, 2, 6 };
    auto sorted_numbers = heap_sort(numbers);
    cout << '\n';
    for (auto s : sorted_numbers)
        cout << s << ' ';
}
int main(){
    demo_pyramid();
    return 0;
}