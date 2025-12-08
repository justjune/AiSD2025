#ifndef L0804_287_H
#define L0804_287_H

#include <iostream>

const int MAXV = 100;            // Максимальное количество вершин в графе
const int MAXINT = 1000000;

// Структура ребра
struct edgenode {
    int y;                       // Номер вершины, в которую ведет это ребро
    int weight;
    edgenode* next;
};

// Структура графа
struct graph {
    edgenode* edges[MAXV+1];    // Массив списков смежности
    int nvertices;              // Количество вершин
    int nedges;                 // Количество ребер
    bool directed;              // Ориентированный ли граф
};

void initialize_graph(graph* g, bool directed);
void insert_edge(graph* g, int x, int y, int weight, bool directed);
int prim(graph* g, int start);

#endif
