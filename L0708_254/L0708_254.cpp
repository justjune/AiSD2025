// Михайлова Юлия, МХ-201, Инициализация вершин (обход в ширину), L0708_254


#include "L0708_254.hpp"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

#define MAXV 100				// Максимальное количество вершин

void initialize_search(Graph *g) {

vector<bool> processed(MAXV+1);			// Обработанные вершины 
vector<bool> discovered(MAXV+1);		// Открытые вершины 
vector<int>  parent(MAXV+1);			// Отношения открытия

//int time = 0;

for (int i = 0; i <= g->nvertices; ++i) {
    processed[i] = false;    			// Вершина не обработана
    discovered[i] = false;   			// Вершина не открыта
    parent[i] = -1;          			// Нет родителя
    }
}

void initialize_graph(Graph &g, bool directed)		// Листинг 7.2 (Инициализация графа)
{
    g.nvertices = 0;
    g.nedges = 0;
    g.directed = directed;
    g.degree.resize(MAXV, 0);
    g.edges.resize(MAXV);
}

void read_graph(Graph &g, bool directed,  ifstream &cin) {      // Листинг 7.3 (Чтение графа из файла)
    int m;						
    int x, y;							
	initialize_graph(g, directed);
     cin >> g.nvertices;					
  cin >> m;							

    for (int i = 0; i < m; i++) {
        cin >> x;
        cin >> y;					
	insert_edge(&g, x, y, directed);		
    }
}


void insert_edge(Graph* g, int x, int y, bool directed) {	//Листинг 7.4 (Вставка ребра)
    EdgeNode* newEdge = new EdgeNode();  
    newEdge->y = y;
    newEdge->weight = 0;
    newEdge->next = g->edges[x];

    g->edges[x] = newEdge;
    g->degree[x]++;

    if (!directed) {
        insert_edge(g, y, x, true);
    } else {
        g->nedges++;
    }
}