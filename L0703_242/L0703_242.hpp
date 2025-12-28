#ifndef L0703_242_HPP
#define L0703_242_HPP
#include "../L0701_241/L0701_241.hpp"
#include "../L0702_242/L0702_242.hpp"
#include <iostream>
#include <vector>
using namespace std;

#define MAXV 100

void read_graph(Graph &g, bool directed, ifstream &cin);
void print_graph(Graph* g);
void insert_edge(Graph *g, int x, int y, bool directed);

#endif