// Prim’s Algorithm for Minimum Spanning Tree

#include "L0804_287.h"

void initialize_graph(graph* g, bool directed) {
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    
    for (int i = 1; i <= MAXV; i++) {
        g->edges[i] = nullptr;
    }
}

void insert_edge(graph* g, int x, int y, int weight, bool directed) {
    edgenode* p = new edgenode;
    
    p->weight = weight;
    p->y = y;
    p->next = g->edges[x];
    g->edges[x] = p;
  
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
    bool intree[MAXV+1];         // Is there a vertex already in the tree?
    int distance[MAXV+1];        // Minimum weight of an edge to a vertex from a tree
    int parent[MAXV+1];          // The ancestor
    int v;                       // Current vertex
    int w;                       // Candidate for the next vertex
    int weight = 0;             

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
            std::cout << "An edge (" << parent[v] << "," << v << ") in the tree \n";
            weight = weight + distance[v];
        }
        p = g->edges[v];
        while (p != nullptr) {
            w = p->y;
            if ((distance[w] > p->weight) && (!intree[w])) {
                distance[w] = p->weight;
                parent[w] = v;
            }
            p = p->next;
        }
        // Search for the next vertex
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
