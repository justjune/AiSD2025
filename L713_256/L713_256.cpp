//L713_256
//Рекурсивное определение пути 
//Черняева Милана МЕН-243201 
#include "L713_256.hpp"
#include <iostream>
using namespace std;

void find_path(int start, int end, int parents[]) {
    if ((start == end) || (end == -1)) {
        cout << start;
    } else {
        find_path(start, parents[end], parents);
        cout << " -> " << end;
    }
}

