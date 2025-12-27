// L0723_272
// Тесты для листинга 7.23
// Гаврилюк Екатерина, МЕН-243201 (ПМ-201)
#include "L0723_272.hpp"
#include "../L0517_194/L0517_194.hpp"
#include "../L0705_244/L0705_244.hpp"
#include <cassert>
#include <iostream>

void test_simple_dag() {
    std::cout << "=== Тест 1: Топологическая сортировка DAG ===\n\n";
    
    Graph g(6);
    
    std::cout << "Создаём граф с 6 вершинами\n";
    std::cout << "Рёбра: 1->2, 1->3, 2->4, 3->4, 3->5, 5->6\n\n";
    
    g.insert_edge(1, 2);
    g.insert_edge(1, 3);
    g.insert_edge(2, 4);
    g.insert_edge(3, 4);
    g.insert_edge(3, 5);
    g.insert_edge(5, 6);
    
    std::cout << "Результат топологической сортировки:\n";
    g.topsort();
    
    std::cout << "\n=== Тест 1 завершён ===\n";
}

void test_with_cycle() {
    std::cout << "\n=== Тест 2: Граф с циклом ===\n\n";
    
    Graph g(3);
    
    std::cout << "Создаём граф с циклом\n";
    std::cout << "Рёбра: 1->2, 2->3, 3->1 (образуют цикл)\n\n";
    
    g.insert_edge(1, 2);
    g.insert_edge(2, 3);
    g.insert_edge(3, 1);
    
    std::cout << "Результат:\n";
    g.topsort();
    
    std::cout << "\n=== Тест 2 завершён ===\n";
}

int main() {
    test_simple_dag();
    test_with_cycle();
    
    return 0;
}
