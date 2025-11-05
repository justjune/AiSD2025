// Михайлова Юлия, МХ-201, Обход графа в ширину, L0709_254

#ifndef L0709_254_HPP
#define L0709_254_HPP

#include <vector>
#include <iostream>
#include <queue>
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
void read_graph(Graph &g, bool directed);
void insert_edge(Graph &g, int x, int y, bool directed);
void bfs(Graph *g, int start);

#endif