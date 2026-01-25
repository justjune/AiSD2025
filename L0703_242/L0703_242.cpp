//Карасс Виталий, МХ-201, Чтение данных графа из потока, L0703_242

#include "L0703_242.hpp"
#include "../L0701_241/L0701_241.hpp"
#include "../L0702_242/L0702_242.hpp"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


void print_graph(Graph* g) {					// Функция печати графа. Листинг 7.5
    for (int i = 1; i < g->nvertices + 1; i++) {
        cout << i << ": ";
        EdgeNode* p = g->edges[i];
        while (p!= nullptr) {
            cout << " " << p->y;
            p = p->next;
        }
        cout << "\n";
    }}


void insert_edge(Graph* g, int x, int y, bool directed) {	// Функция вставки ребра. Листинг 7.4
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


void read_graph(Graph &g, bool directed,  ifstream &cin) {
    int m;							// Количество рёбер
    int x, y;							// Вершины в ребре (x,y)
	initialize_graph(g, directed);
     cin >> g.nvertices;					// Количество вершин	
  cin >> m;							// Количество рёбер

    for (int i = 0; i < m; i++) {
        cin >> x;
        cin >> y;						// Считываем каждое ребро
	insert_edge(&g, x, y, directed);			// Функция вставки ребра
    }

	print_graph (&g);
}

