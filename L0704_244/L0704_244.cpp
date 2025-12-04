#include "L0704_244.hpp"

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
