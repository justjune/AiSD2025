// Михайлова Юлия, МХ-201, Обход графа в ширину, L0709_254


#include "L0709_254.hpp"
#include <iostream>
#include <vector>
using namespace std;



int main() {
Graph graph; 
initialize_graph(graph, false); 
read_graph(graph, false);

int start;
cin >> start;
bfs(&graph, start);

 return 0;
}


