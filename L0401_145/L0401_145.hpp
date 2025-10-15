#ifndef MY_QSORT_H
#define MY_QSORT_H

#include <cstdlib>

template<typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T, typename Compare>
int partition(T arr[], int low, int high, Compare compare) {
    int randomIndex = low + rand() % (high - low + 1);
    
    swap(arr[randomIndex], arr[high]);

    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

template<typename T, typename Compare>
void my_qsort(T arr[], int low, int high, Compare compare) {
    if (low < high) {
        int pi = partition(arr, low, high, compare);
        my_qsort(arr, low, pi - 1, compare);
        my_qsort(arr, pi + 1, high, compare);
    }
}


#endif
