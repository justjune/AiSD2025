#include <vector>
#include <iostream>
#include <cmath>
#include <iterator>

using namespace std;

// indexation from 0
template <typename Item>
struct PriorityQueue
{
    vector<Item> queueBody;

    // size of the pyramid (n in Skiene)
    size_t size() const
    {
        return queueBody.size();
    }

    // returns true if the pyramid is empty, false otherwise
    bool empty() const
    {
        return queueBody.empty();
    }

    // swap elements in pyramid
    void swapElements(size_t index1, size_t index2) {
        swap(queueBody[index1], queueBody[index2]);
    }

    // parent's index if index is not 0, queueBody.size() otherwise
    size_t pq_parent(size_t index) const
    {
        if (index == 0 or index >= queueBody.size())
            return queueBody.size();
        return (index - 1) / 2;
    }

    // left child
    size_t pq_young_child(size_t index) const
    {
        return index * 2 + 1;
    }

    // right child
    size_t pq_old_child(size_t index) const
    {
        return index * 2 + 2;
    }

    // sorting
    void bubble_up(size_t index)
    {
        auto parent_index = pq_parent(index);
        if (parent_index != queueBody.size() && queueBody[parent_index] > queueBody[index])
        {
            swapElements(index, parent_index);
            bubble_up(parent_index);
        }
    }

    void bubble_up_no_reqursion(size_t index)
    {
        while (index > 0)
        {
            size_t parent_index = (index - 1) / 2;
            if (queueBody[parent_index] <= queueBody[index])
                break;
            swapElements(index, parent_index);
            index = parent_index;
        }
    }

    // inser element
    void pq_insert(Item element)
    {
        // there is no need to check for excess size due to using vector
        queueBody.push_back(element);
        // no stack overflowed version
        // queueBody.bubble_up(queueBody.size() - 1);
        bubble_up_no_reqursion(queueBody.size() - 1);
    }

    // reqursion algorythm
    void bubble_down(size_t index)
    {
        size_t c = pq_young_child(index);
        size_t min_index = index;

        for (size_t i = 0; i <= 1; i++)
        {
            if ((c + i) < queueBody.size())
            {
                if (queueBody[min_index] > queueBody[c + i])
                    min_index = c + i;
            }
        }
        if (min_index != index)
        {
            swapElements(index, min_index);
            bubble_down(min_index);
        }
    }

    // no reqursion algorythm
    void bubble_down_no_reqursion(size_t index)
    {
        while (index < queueBody.size())
        {
            size_t min_index = index;
            size_t c = pq_young_child(index);

            for (size_t i = 0; i <= 1; i++)
            {
                if ((c + i) < queueBody.size())
                {
                    if (queueBody[min_index] > queueBody[c + i])
                        min_index = c + i;
                }
            }
            if (min_index == index)
                break;

            swapElements(index, min_index);
            index = min_index;
        }
    }

    template<typename Container>
    void make_heap_fast(Container& elements)
    {

        queueBody.assign(begin(elements), end(elements));
        // replace queueBody to elements from diapazone
        for (int i = queueBody.size() / 2 - 1; i >= 0; i--)
            bubble_down_no_reqursion(i);
    }

    // pretty print pyramid
    void print()
    {
        size_t i = 0, power = 0;

        // println("\nPyramid:");
        cout << "\nPyramid:\n";
        while (i < queueBody.size())
        {
            for (size_t j = 0; j < pow(2, power) && i < queueBody.size(); ++j)
            {
                cout << queueBody[i] << " ";
                i++;
            }
            //println();
            cout << '\n';
            power++;
        }
    }
    int heap_compare(size_t index, int k, const Item& x)
    { 
        if (k <= 0 || index >= queueBody.size())
            return k;
        
        if (queueBody[index] < x) 
        {
            k = heap_compare(pq_young_child(index), k - 1, x);
            if (k > 0) 
                k = heap_compare(pq_old_child(index), k, x);
        }
        return k;
    }

    template<typename Container>
    void make_heap(Container& elements) {

        queueBody.clear(); // if pyramid already existed
        // to make_heap_fast assign reinitialize queueBody, becouse
        // don't need to clean it
        for (auto el = begin(elements); el != end(elements); ++el)
            pq_insert(*el);

    }

    Item extract_min()
    {
        if (queueBody.empty())
        {
            cout << "Priority queue is empty";
            return -1;
            // -1 like Skien
        }
        else
        {
            Item min = queueBody[0];
            queueBody[0] = queueBody.back();
            queueBody.pop_back();
            if (!queueBody.empty())
                bubble_down_no_reqursion(0);
            return min;
        }
    }
};

template<typename Container>
auto heap_sort(Container& elements)
{
    using Item = typename Container::value_type;

    PriorityQueue<Item> pyramid;
    pyramid.make_heap(elements);

    for (size_t i = 0; i < elements.size(); i++)
        elements[i] = pyramid.extract_min();

    return elements;
}


void demo_pyramid()
{
    PriorityQueue<int> pq;

    pq.pq_insert(10);
    pq.pq_insert(5);
    pq.pq_insert(15);
    pq.pq_insert(3);
    pq.pq_insert(7);
    pq.pq_insert(6);
    pq.pq_insert(2);
    pq.pq_insert(4);
    pq.pq_insert(14);
    pq.pq_insert(16);

    pq.print();

    PriorityQueue<int> fast_test;
    vector<int> vec = { 4, 5, 7, 5, 2, 1 };
    fast_test.make_heap_fast(vec);
    fast_test.print();
    
    int i = pq.heap_compare(3, 6, 12);
    cout << "\nheap compare k = " << i << '\n';
    
    PriorityQueue<int> make_heap_test;
    int lst[] = {8, 3, 6, 1, 9};
    make_heap_test.make_heap(lst);
    make_heap_test.print();
    
    vector<int> numbers = { 3, 1, 4, 1, 5, 9, 2, 6 };
    auto sorted_numbers = heap_sort(numbers);
    cout << '\n';
    for (auto s : sorted_numbers)
        cout << s<< ' ' ;

}

int main()
{
    demo_pyramid();
    return 0;
}
