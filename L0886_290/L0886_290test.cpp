#include "L0886_290.hpp"
#include <iostream>

int main() {
    // Пример графа с 4 вершинами и 5 ребрами
    std::vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    
    int num_vertices = 4;
    int mst_weight = kruskal(edges, num_vertices);
    
    std::cout << "Вес минимального остовного дерева: " << mst_weight << std::endl;
    
    return 0;
}