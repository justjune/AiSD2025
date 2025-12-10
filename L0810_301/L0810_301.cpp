#include "L0810_301.hpp"

//Подготовка графа
void prepare_graph(graph* g, bool directed) {
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    
     int i = 1;
    while (i <= MAXV) {
        g->edges[i] = nullptr;
        i++;
    }
}

//Создание связи между узлами
void add_connection(graph* g, int x, int y, int weight, bool directed) {
    edgenode* new_edge = new edgenode;
    
    new_edge->weight = weight;
    new_edge->y = y;
    new_edge->next = g->edges[x];
    g->edges[x] = new_edge;
   
    if (!directed) {
        add_connection(g, y, x, weight, true);
    } else {
        g->nedges++;
    }
}

//Алгоритм Дейкстры
int dijkstra(graph* g, int start) {
    int i;                 /* Счетчик */
    edgenode* p;           /* Временный указатель */ 
    bool intree[MAXV+1];   /* Вершина уже в дереве?*/   
    int distance[MAXV+1];  /* Стоимость добавления в дерево */ 
    int parent[MAXV+1];    /* Предок в дереве */
    int v;                 /* Текущая вершина для обработки */     
    int w;                 /* Кандидат на следующую вершину */
    int dist;              /* Наименьшая стоимость расширения дерева*/      
    int weight = 0;        /* Вес дерева */     

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
            printf("edge (%d, %d) in tree \n", parent[v], v);
            weight = weight + distance[v];
        }
      
        p = g->edges[v];
        while (p != nullptr) {
            w = p->y;
            if (distance[w] > (distance[v] + p->weight)) {
                distance[w] = distance[v] + p->weight;
                parent[w] = v;
            }
            p = p->next;
        }
       
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
