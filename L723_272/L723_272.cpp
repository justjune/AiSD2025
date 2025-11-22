//L723_272
//Топологическая сортировка
//Гаврилюк Екатерина, МЕН-243201 (ПМ-201) 11.11.2025
#include <iostream>
#include <stack>
#include "L723_272.hpp"
using namespace std;

stack<int> sorted;              /* Стек для результата */

void process_vertex_late(int v) {
    sorted.push(v);
}

void process_edge(int x, int y) {
    int edge_class;             /* Класс ребра */

    edge_class = edge_classification(x, y);

    if (edge_class == BACK) {
        cout << "Warning: directed cycle found, not a DAG\n";
        // Внимание: обнаружен ориентированный цикл,
        // неориентированный граф
    }
}

void topsort(graph *g) {
    int i;                      /* Счётчик */

    while (!sorted.empty()) sorted.pop();

    for (i = 1; i <= g->nvertices; i++) {
        if (!discovered[i])
            dfs(g, i);
    }

    print_stack(sorted);        /* Вывод топологического упорядочивания */
}