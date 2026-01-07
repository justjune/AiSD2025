#ifndef L0804_287_H
#define L0804_287_H

#include <iostream>

const int MAXV = 100;
const int MAXINT = 1000000;

// Структура ребра
struct edgenode {
    int y;                   
    int weight;
    edgenode* next;
};

// Структура графа
struct graph {
    edgenode* edges[MAXV+1];    
    int nvertices;             
    int nedges;                 
    bool directed;            
};

void initialize_graph(graph* g, bool directed);
void insert_edge(graph* g, int x, int y, int weight, bool directed);
int prim(graph* g, int start);

#endif
