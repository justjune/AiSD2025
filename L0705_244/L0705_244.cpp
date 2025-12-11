#include "L0705_244.hpp"
#include <iostream>

//Функция для вывода графа 
void print_graph(graph *g) {
    for (int i = 1; i <= g->nvertices; i++) {
        std::cout << i << ": "; // выводим номер вершины
        edgenode *p = g->edges[i]; // берем все ребра для i-ой вершины
        // проходим по всем ребрам i-ой вершины
        while (p != nullptr) {
            std::cout << ' ' << p->y; // выводим точку соединенную с i-ой вершиной
            p = p->next;              // идем в следующее ребро
        }
        std::cout << std::endl;
    }
}