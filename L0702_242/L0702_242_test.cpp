//Карасс Виталий, МХ-201,Инициализация графа, L0702_242

#include "L0702_242.hpp"
#include "../L0701_241/L0701_241.hpp"
#include <iostream>
using namespace std;

#define MAXV 100

int main() {
Graph graph; 
initialize_graph (graph, 0);
				// Проверка инициализации
if (graph.nvertices != 0 or graph.nedges != 0 or graph.degree.size() != MAXV or graph.edges.size() != MAXV) {
  cout << "error initialize_graph";
    }

 return 0;
}