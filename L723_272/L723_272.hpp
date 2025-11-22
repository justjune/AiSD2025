#ifndef L723_272.HPP
#define L723_272.HPP

#include <stack>
#include <iostream>
#include <vector>
using namespace std;

/* Определения вспомогательных структур и констант */

struct graph {
    int nvertices;
    vector<vector<int>> adj;    // список смежности
};

extern vector<bool> discovered; // посещённые вершины
extern stack<int> sorted;       // стек для топологического порядка

enum EdgeClass { TREE, BACK, FORWARD, CROSS }; // типы рёбер

/* Прототипы используемых функций */

int edge_classification(int x, int y);  // классификация ребра
void dfs(graph *g, int v);              // обход в глубину
void print_stack(stack<int> s);         // вывод содержимого стека

/* Основные функции топологической сортировки */

void process_vertex_late(int v);
void process_edge(int x, int y);
void topsort(graph *g);

#endif