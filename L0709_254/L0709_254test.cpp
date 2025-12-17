// Михайлова Юлия, МХ-201, Обход графа в ширину, L0709_254


#include "L0709_254.hpp"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;



int main() { 
int start;
cin >> start;

Graph graph; 
initialize_graph(graph, false); 
ifstream cin("L0709_254test.txt");		// Листинг 7.3
read_graph(graph, false, cin);


bfs(&graph, start);

 return 0;
}


