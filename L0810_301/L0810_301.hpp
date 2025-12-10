#ifndef L0810_301_HPP
#define L0810_301_HPP

#define MAXV 1000
#define MAXINT 2147483647

struct edgenode {
    int dest;          
    int value;         
    edgenode* link;   
};

struct graph {
    edgenode* list[MAXV+1];  //Списки для каждой вершины
    int count[MAXV+1];       //Сколько ребер выходит
    int nodes;               //Кол-во вершин
    int edges;               //Кол-во ребер
    bool dir;                //Направленный ли
};

void make_graph(graph* g, bool dir);
void add_edge(graph* g, int a, int b, int val, bool dir);
int shortest(graph* g, int start);

#endif
