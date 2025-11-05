// Михайлова Юлия, МХ-201, Инициализация вершин (обход в ширину), L0708_254


#include "L0708_254.hpp"
#include <vector>
#include <iostream>
using namespace std;

#define MAXV 100				// Максимальное количество вершин

void initialize_search(Graph *g) {

vector<bool> processed(MAXV+1);			// Обработанные вершины 
vector<bool> discovered(MAXV+1);		// Открытые вершины 
vector<int>  parent(MAXV+1);			// Отношения открытия

//int time = 0;

for (int i = 0; i <= g->nvertices; ++i) {
    processed[i] = false;    
    discovered[i] = false;   
    parent[i] = -1;          
    }
}