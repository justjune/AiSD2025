#ifndef L0714_257_HPP
#define L0714_257_HPP
#define MAXV 100

struct edgenode {
    int y;               // Вторая(конечная) точка ребра
    int weight;          // вес ребра
    edgenode *next;      // следующее ребро
};

struct graph {
    edgenode *edges[MAXV + 1];  // Информация о ребрах
    int degree[MAXV + 1];        // степень каждой вершины
    int nvertices;               // Количество вершин в графе
    int nedges;                  // Количество ребер
    bool directed;               // Ориентированный граф?
};
void initialize_graph(graph *g, bool directed);
void insert_edge(graph *g, int x, int y, bool directed);
void connected_components(graph* g);

#endif