// Михайлова Юлия, МХ-201, Инициализация вершин (обход в ширину), L0708_254


#include "L0708_254.hpp"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;



int main() {
Graph graph; 
initialize_graph(graph, false); 
ifstream cin("L0708_254test.txt");		// Листинг 7.3
read_graph(graph, false, cin);

initialize_search(&graph);

 return 0;
}