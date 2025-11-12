#ifndef L0703_242_HPP
#define L0703_242_HPP

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
void read_graph(Graph &g, bool directed);

struct List;

#endif