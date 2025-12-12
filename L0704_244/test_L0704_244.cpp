#include "L0704_244.hpp"
#include <iostream>
using namespace std;

#define MAXV 100

int main() {
    Graph g(MAXV);
    g.directed = false; // или true, по необходимости

    // Проверка инициализации
    if (g.nvertices != MAXV || g.nedges != 0 || g.degree.size() != MAXV || g.edges.size() != MAXV) {
        cout << "error initialize_graph\n";
        return 1;
    }

    // Вставка ребер для теста
    insert_edge(&g, 0, 1, g.directed);
    insert_edge(&g, 1, 2, g.directed);

    // Вывод списка соседей
    for (int i = 0; i < 3; ++i) {
        cout << "Vertex " << i << ":";
        EdgeNode* p = g.edges[i];
        while (p) {
            cout << " -> " << p->y;
            p = p->next;
        }
        cout << "\n";
    }

    cout << "Total edges: " << g.nedges << "\n";

    return 0;
}
