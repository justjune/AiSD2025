#ifndef L0410_160_HPP
#define L0410_160_HPP

#include <vector>

#define QUEUESIZE 1000

typedef int item_type;

struct queue {
    int /*item_type*/ q[QUEUESIZE+1];   /* body of queue */
    int first;                          /* position of first element */
    int last;                           /* position of last element */
    int count;                          /* number of queue elements */
};

void merge_sort(std::vector<int>& s, int low, int high);

void merge(std::vector<int>& s, int low, int middle, int high);

#endif
