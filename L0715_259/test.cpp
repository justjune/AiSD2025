#include "graph.hpp"
#include <iostream>
using namespace std;


int main(){
    cout << "=== ТЕСТ 1: Ориентированный двудольный граф ===" << endl;
    
    Graph g;
    g.init_graph(&g, true); // ориентированный граф
    
    // Создаем простой ориентированный двудольный граф
    // 0 -> 2, 0 -> 3, 1 -> 2, 1 -> 3
    g.nvertices = 4;
    
    g.ins_edge(&g, 0, 2, true);
    g.ins_edge(&g, 0, 3, true);
    g.ins_edge(&g, 1, 2, true);
    g.ins_edge(&g, 1, 3, true);
    
    cout << "Ориентированный двудольный граф до расскраски:" << endl;
    g.print_color_graph(&g);
    
    cout << "Проверка двудольности..." << endl;
    g.two_color(&g);

    cout << "Граф после расскраски: " << endl;
    g.print_color_graph(&g);
    
    //////////////////////////////////////////////////////////////////
    
    cout << "=== Тест 2: Ориентированный НЕдвудольный граф ===" << endl;

    g.init_graph(&g, true); // ориентированный граф
    
    // Создаем ориентированный треугольник (цикл)
    // 0 -> 1, 1 -> 2, 2 -> 0
    g.nvertices = 3;
    
    g.ins_edge(&g, 0, 1, true);
    g.ins_edge(&g, 1, 2, true);
    g.ins_edge(&g, 2, 0, true);
    
    cout << "Ориентированный треугольник:" << endl;
    g.print_color_graph(&g);
    
    cout << "Проверка двудольности..." << endl;
    g.two_color(&g);
    
    cout << endl;
    cin.get();

}
