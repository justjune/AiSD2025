#ifndef MERGE_HPP
#define MERGE_HPP

#include <queue>
#include <vector>
#include <span> 

using namespace std;

template<typename Item>
void merge(span<Item> s, int low, int middle, int high) 
{
    int i;  
    queue<Item> buffer1, buffer2; 

    for (i = low; i <= middle; i++) 
        buffer1.push(s[i]);
    
    for ( i = middle + 1; i <= high; i++) 
        buffer2.push(s[i]);

    i = low;
    while (!buffer1.empty() && !buffer2.empty()) 
    {
        if (buffer1.front() <= buffer2.front()) 
        {
            s[i++] = buffer1.front(); 
            buffer1.pop(); 
        } 
        else 
        {
            s[i++] = buffer2.front();
            buffer2.pop();
        }
    }

    while (!buffer1.empty()) 
    {
        s[i++] = buffer1.front();
        buffer1.pop();
    }
    
    while (!buffer2.empty()) 
    {
        s[i++] = buffer2.front();
        buffer2.pop();
    }
}

#endif
    
