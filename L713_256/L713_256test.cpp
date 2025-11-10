#include "L713_256.hpp"
#include <iostream>
using namespace std;

int main() { 
    // BFS обход из вершины 0
    int parents[] = {-1, 0, 1, 2, 0, 4, 2, 4, 7};
    // Индексы:    [0] [1][2][3][4][5][6][7][8]
    // Вершины:     0   1  2  3  4  5  6  7  8
    // Родители:   -1  0  1  2  0  4  2  4  7
    
    // Тестируем различные пути в графе
    find_path(0, 3, parents);
    cout << endl;
    
    find_path(0, 5, parents);
    cout << endl;
    
    find_path(0, 8, parents);
    cout << endl;
    
    find_path(1, 6, parents);
    cout << endl;
    
    find_path(4, 8, parents);
    cout << endl;
    
    find_path(2, 6, parents);
    cout << endl;
    
    return 0;
