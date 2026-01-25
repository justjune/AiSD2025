//Карасс Виталий, МХ-201, , Инициализация графа, L0702_242

#include "L0702_242.hpp"
#include "../L0701_241/L0701_241.hpp"
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

