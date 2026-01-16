#include "L0433_150.hpp"
#include <iostream>
#include <vector>

using namespace std;

void demo_basic_operations()
{
    cout << "=== Demo: basic operations ===\n";

    PriorityQueue<int> pq;

    cout << "empty = " << pq.empty() << '\n';
    cout << "size = " << pq.size() << '\n';

    pq.queueBody = {7, 5, 6, 4, 3, 2, 1};

    cout << "\nInitial array (not a heap):\n";
    pq.print();
}

void demo_bubble_down_recursive()
{
    cout << "\n=== Demo: bubble_down (recursive) ===\n";

    PriorityQueue<int> pq;
    pq.queueBody = {9, 3, 4, 1, 5, 6, 2};

    cout << "Before bubble_down:\n";
    pq.print();

    pq.bubble_down(0);

    cout << "\nAfter bubble_down from index 0:\n";
    pq.print();
}

void demo_bubble_down_no_recursion()
{
    cout << "\n=== Demo: bubble_down_no_reqursion ===\n";

    PriorityQueue<int> pq;
    pq.queueBody = {8, 4, 7, 3, 6, 5, 1};

    cout << "Before bubble_down_no_reqursion:\n";
    pq.print();

    pq.bubble_down_no_reqursion(0);

    cout << "\nAfter bubble_down_no_reqursion from index 0:\n";
    pq.print();
}

void demo_extract_min()
{
    cout << "\n=== Demo: extract_min ===\n";

    PriorityQueue<int> pq;
    pq.queueBody = {1, 3, 2, 7, 6, 4, 5};

    cout << "Initial heap:\n";
    pq.print();

    while (!pq.empty())
    {
        int m = pq.extract_min();
        cout << "\nextract_min = " << m << '\n';
        pq.print();
    }
}

void demo_indices()
{
    cout << "\n=== Demo: parent / children indices ===\n";

    PriorityQueue<int> pq;
    pq.queueBody = {1, 3, 2, 7, 6, 4, 5};

    for (size_t i = 0; i < pq.size(); ++i)
    {
        cout << "index " << i
             << ", value = " << pq.queueBody[i]
             << ", parent = " << pq.pq_parent(i)
             << ", left = " << pq.pq_young_child(i)
             << ", right = " << pq.pq_old_child(i)
             << '\n';
    }
}

int main()
{
    demo_basic_operations();
    demo_bubble_down_recursive();
    demo_bubble_down_no_recursion();
    demo_extract_min();
    demo_indices();

    return 0;
}
