//Карасс Виталий, МХ-201,Инициализация графа, L0702_242

#include <iostream>
#include "L0702_242.hpp"
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



int main() {
Graph graph; 
initialize_graph (graph, 0);

 return 0;
}