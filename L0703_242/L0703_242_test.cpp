//Карасс Виталий, МХ-201, Чтение данных графа из потока, L0703_242

//L0703_242
#include "../L0701_241/L0701_241.hpp"
#include "../L0702_242/L0702_242.hpp"
#include "L0703_242.hpp"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;



int main() {
Graph graph; 
ifstream cin("L0703_242_test.txt");		// Переобозначение для чтения из файла
read_graph(graph, false, cin);

 return 0;
}