#include "L0705_244.hpp"
#include <iostream>
using namespace std;

#define MAXV 100

int main() {
    Graph g(MAXV);
    g.directed = false; // или true, по необходимости

    // Проверка инициализации
    if (g.nvertices != MAXV || g.nedges != 0 || g.degree.size() != MAXV + 1 || g.edges.size() != MAXV + 1) {
        cout << "error initialize_graph\n";
        return 1;
    }

    // Вставка ребер для теста
    insert_edge(&g, 1, 2, g.directed);
    insert_edge(&g, 2, 3, g.directed);

    // Вывод графа
    print_graph(&g);

    cout << "Total edges: " << g.nedges << "\n";

    return 0;
}
