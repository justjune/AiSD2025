// Михайлова Юлия, МХ-201, Инициализация вершин (обход в ширину), L0708_254

#ifndef L0708_254_HPP
#define L0708_254_HPP

#include <iostream>
#include <vector>
using namespace std;

#define MAXV 100

struct EdgeNode {
int y;
int weight;
struct EdgeNode *next;
};

struct Graph {
vector<EdgeNode*> edges;
vector<int> degree;
int nvertices;
int nedges;
int directed;
};
void initialize_graph(Graph &g, bool directed);
void read_graph(Graph &g, bool directed, ifstream &cin);
void insert_edge(Graph *g, int x, int y, bool directed);

void initialize_search(Graph *g);

#endif