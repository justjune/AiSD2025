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

    template<typename Container>
    void make_heap(Container& elements) {

        queueBody.clear(); // if pyramid already existed
        // to make_heap_fast assign reinitialize queueBody, becouse
        // don't need to clean it
        for (auto el = begin(elements); el != end(elements); ++el)
            pq_insert(*el);

    }

};

int main()
{
    return 0;
}
