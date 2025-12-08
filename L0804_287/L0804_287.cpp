// Алгоритм Прима — алгоритм построения минимального остовного дерева (минимального остова) взвешенного связного неориентированного графа.

#include "L0804_287.h"

// Инициализация графа
void initialize_graph(graph* g, bool directed) {
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    
    for (int i = 1; i <= MAXV; i++) {
        g->edges[i] = nullptr;
    }
}

// Добавление ребра между вершинами
void insert_edge(graph* g, int x, int y, int weight, bool directed) {
    edgenode* p = new edgenode;
    
    p->weight = weight;
    p->y = y;
    p->next = g->edges[x];
    g->edges[x] = p;
  
    // Если граф неориентированный, добавить обратное ребро
    if (!directed) {
        insert_edge(g, y, x, weight, true);
    } else {
        g->nedges++;
    }
}

// Алгоритм Прима
int prim(graph* g, int start) {
    int i;
    edgenode* p;
    int dist;
    bool intree[MAXV+1];         // Есть ли вершина уже в дереве?
    int distance[MAXV+1];        // Минимальный вес ребра до вершины от дерева
    int parent[MAXV+1];          // Предок в дереве
    int v;                       // Текущая вершина для обработки
    int w;                       // Кандидат на следующую вершину
    int weight = 0;              // Вес всего дерева

    // Инициализация
    for (i = 1; i <= g->nvertices; i++) {
        intree[i] = false;
        distance[i] = MAXINT;
        parent[i] = -1;
    }

    distance[start] = 0;
    v = start;

    while (!intree[v]) {
        intree[v] = true;
        
        if (v != start) {
            std::cout << "Ребро (" << parent[v] << "," << v << ") в дереве \n";
            weight = weight + distance[v];
        }
        // Обход всех ребер, исходящие из текущей вершины
        p = g->edges[v];
        while (p != nullptr) {
            w = p->y;
            if ((distance[w] > p->weight) && (!intree[w])) {
                distance[w] = p->weight;
                parent[w] = v;
            }
            p = p->next;
        }
        // Поиск следующей вершины для добавления в дерево
        dist = MAXINT;
        for (i = 1; i <= g->nvertices; i++) {
            if ((!intree[i]) && (dist > distance[i])) {
                dist = distance[i];
                v = i;
            }
        }
    }
    
    return weight;
}
