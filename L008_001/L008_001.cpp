struct graph{
    edgenode *edges[MAXV+1];  /* Массив указателей на списки смежности */
    int degree[MAXV+1];       /* Степень каждой вершины */
    int nvertices;            /* Количество вершин в графе */
    int nedges;               /* Количество ребер в графе */
    int directed;             /* Граф ориентированный? */
};


typedef struct edgenode {
    int y;                    /* Номер смежной вершины */
    int weight;               /* Вес ребра, если есть */
    struct edgenode *next;    /* Указатель на следующее ребро в списке */
} edgenode;