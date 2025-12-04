#include "L0705_244.hpp"

// Реализация функции вставки ребра
void insert_edge(Graph* g, int x, int y, bool directed) {
    EdgeNode* p = new EdgeNode;
    p->weight = 0;
    p->y = y;
    p->next = g->edges[x];
    g->edges[x] = p;
    g->degree[x]++;

    if (!directed) {
        insert_edge(g, y, x, true);
    } else {
        g->nedges++;
    }
}

// Реализация функции вывода графа
void print_graph(const Graph* g) {
    int i;                 // Счетчик
    EdgeNode* p;           // Временный указатель

    for (i = 1; i <= g->nvertices; i++) {
        std::cout << i << ": "; // Выводим вершину
        p = g->edges[i];

        while (p != nullptr) {  // Перебираем все смежные вершины
            std::cout << " " << p->y;
            p = p->next;
        }
        std::cout << std::endl; // Переход на новую строку
    }
}
