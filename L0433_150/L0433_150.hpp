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



