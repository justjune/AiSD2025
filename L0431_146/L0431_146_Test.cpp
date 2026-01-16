#include "L0431_146.hpp"
#include <iostream>
#include <vector>

using namespace std;

void demo_priority_queue()
{
    cout << "=== Demo: pq_insert ===\n";

    PriorityQueue<int> pq;
    pq.pq_insert(4);
    pq.pq_insert(5);
    pq.pq_insert(7);
    pq.pq_insert(5);
    pq.pq_insert(2);
    pq.pq_insert(1);

    cout << "After inserts:\n";
    pq.print();

    cout << "\nsize = " << pq.size() << '\n';
    cout << "empty = " << pq.empty() << '\n';

    cout << "\n=== Demo: make_heap ===\n";

    PriorityQueue<int> pq2;
    vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6};

    pq2.make_heap(vec);
    pq2.print();

    cout << "\n=== Demo: parent / children indices ===\n";

    for (size_t i = 0; i < pq2.size(); ++i)
    {
        cout << "index " << i
             << ", value = " << pq2.queueBody[i]
             << ", parent = " << pq2.pq_parent(i)
             << ", left = " << pq2.pq_young_child(i)
             << ", right = " << pq2.pq_old_child(i)
             << '\n';
    }
}

int main()
{
    demo_priority_queue();
    return 0;
}
