#include "L0410_160.hpp"
#include <iostream>

using namespace std;

void init_queue(queue *q) {
    q->first = 0;
    q->last = QUEUESIZE - 1;
    q->count = 0;
}

void enqueue(queue *q, item_type x) {
    if (q->count >= QUEUESIZE) {
        cout << "Warning: queue overflow enqueue x=" <<  x << '\n';
    } else {
        q->last = (q->last + 1) % QUEUESIZE;
        q->q[q->last] = x;    
        q->count = q->count + 1;
    }
}

item_type dequeue(queue *q) {
    item_type x;

    if (q->count <= 0) {
        cout << "Warning: empty queue dequeue.\n";
    } else {
        x = q->q[q->first];
        q->first = (q->first + 1) % QUEUESIZE;
        q->count = q->count - 1;
    }
    return(x);
}

item_type headq(queue *q) {
    return(q->q[q->first]);
}

int empty_queue(queue *q) {
    if (q->count <= 0) {
        return (true);
    }
    return (false);
}

void print_queue(queue *q) {
    int i, j;

    i = q->first; 
        
    while (i != q->last) {
        cout << q->q[i] << ' ';
        i = (i + 1) % QUEUESIZE;
    }

    cout << q->q[i] << ' ';

    cout << "\n";
}

void merge(std::vector<item_type>& s, int low, int middle, int high) {
    int i;                  /* counter */
    queue buffer1, buffer2; /* buffers to hold elements for merging */

    init_queue(&buffer1);
    init_queue(&buffer2);

    for (i = low; i <= middle; i++) {
        enqueue(&buffer1, s[i]);
    }

    for (i = middle + 1; i <= high; i++) {
        enqueue(&buffer2, s[i]);
    }

    i = low;
    while (!(empty_queue(&buffer1) || empty_queue(&buffer2))) {
        if (headq(&buffer1) <= headq(&buffer2)) {
            s[i++] = dequeue(&buffer1);
        } else {
            s[i++] = dequeue(&buffer2);
        }
    }

    while (!empty_queue(&buffer1)) {
        s[i++] = dequeue(&buffer1);
    }

    while (!empty_queue(&buffer2)) {
        s[i++] = dequeue(&buffer2);
    }
}

// Реализация сортировки слиянием
void merge_sort(std::vector<item_type>& s, int low, int high) {
    if (low < high) {
        int middle = (low + high) / 2;

        merge_sort(s, low, middle);
        merge_sort(s, middle + 1, high);

        merge(s, low, middle, high);
    }
}
