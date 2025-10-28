//Карасс Виталий, МХ-201, Чтение данных графа из потока, L0703_242

//L0703_242

#include "L0703_242.hpp"
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

void initialize_graph(Graph &g, bool directed) {
    g.nvertices = 0;
    g.nedges = 0;
    g.directed = directed;
    g.degree.resize(MAXV, 0);
    g.edges.resize(MAXV);
}


int main() {
Graph graph; 
read_graph (graph, false);


 return 0;
}