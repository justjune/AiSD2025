//L0723_272
//Топологическая сортировка
//Гаврилюк Екатерина, МЕН-243201 (ПМ-201) 11.11.2025
#include "L0723_272.hpp"
#include <iostream>

void Graph::process_vertex_late(int v) {
    sorted.push(v);
}

void Graph::process_edge(int x, int y) {
    EdgeClass edge_class = edge_classification(x, y);

    if (edge_class == BACK) {
        std::cout << "Warning: directed cycle found, not a DAG\n";
    }
}

void Graph::topsort() {
    // Очистить стек
    while (!sorted.empty()) {
        sorted.pop();
    }

    for (int i = 1; i <= nvertices; i++) {
        if (!discovered[i]) {
            dfs(i);
        }
    }

    // Вывод топологического упорядочивания
    while (!sorted.empty()) {
        std::cout << sorted.top() << " ";
        sorted.pop();
    }
    std::cout << "\n";
}
