//Карасс Виталий, МХ-201, Чтение данных графа из потока, L0703_242

#include "L0703_242.hpp"
#include <iostream>
#include <vector>
using namespace std;



void initialize_graph(Graph &g, bool directed) {
    g.nvertices = 0;
    g.nedges = 0;
    g.directed = directed;
    g.degree.resize(MAXV, 0);
    g.edges.resize(MAXV);
}

void read_graph(Graph &g, bool directed) {
    int m;							// Количество рёбер
    int x, y;							// Вершины в ребре (x,y)

    cin >> g.nvertices;						// Количество вершин
    cin >> m;							// Количество рёбер
    initialize_graph(g, directed);

    for (int i = 0; i < m; i++) {
        cin >> x;
        cin >> y;						// Считываем каждое ребро
   // insert_edge(&g, x, y, directed);				// Функция вставки ребра
    }
}

