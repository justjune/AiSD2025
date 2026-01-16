#include <iostream>
#include <vector>
#include <span> 
#include <algorithm>

using namespace std;

template<typename Item>
int partition(span<Item> arr, int low, int high) 
{
    
    int mid = low + (high - low) / 2;
    Item pivot = arr[mid];
    
    swap(arr[mid], arr[high]);
    
    int i = low;
    
    for (int j = low; j < high; j++) 
    {
        if (arr[j] < pivot) 
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

template<typename Item>
void quicksort(span<Item> arr, int low, int high) 
{
    while (low < high) 
    {
        int p = partition(arr, low, high);
        
        if (p - low < high - p) 
        {
            quicksort(arr, low, p - 1);
            low = p + 1;
        } 
        else 
        {
            quicksort(arr, p + 1, high);
            high = p - 1;
        }
    }
}
