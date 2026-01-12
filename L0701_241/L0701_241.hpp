#ifndef L0701_241_HPP
#define L0701_241_HPP

#include <iostream>
#include <vector>
using namespace std;

#define MAXV 100			// Максимальное количество вершин

struct EdgeNode {
int y;					// Информация о смежности
int weight;				// Вес ребра, если есть
struct EdgeNode *next;			// Следующее ребро в списке
};


struct Graph {
vector<EdgeNode*> edges;		// Информация о смежности
vector<int> degree;			// Степень каждой вершины
int nvertices;				// Количество вершин в графе
int nedges;				// Количество ребер в графе
int directed;				// Граф ориентированный?
};

#endif