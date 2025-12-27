// L0724_273
// Тесты для листинга 7.24
// Гаврилюк Екатерина, МЕН-243201 (ПМ-201)
#include "L0724_273.hpp"
#include <iostream>

void print_graph(Graph* g, int n) {
    for (int i = 1; i <= n; i++) {
        std::cout << i << " -> ";
        const auto& edges = g->get_edges(i);
        if (edges.empty()) {
            std::cout << "(нет рёбер)";
        }
        for (int j : edges) {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
}

void test_transpose() {
    std::cout << "=== Тест транспонирования графа ===\n\n";
    
    Graph* g = new Graph(5);
    
    std::cout << "Создаём граф с 5 вершинами\n";
    std::cout << "Добавляем рёбра: 1->2, 1->3, 2->4, 3->4, 4->5\n\n";
    g->insert_edge(1, 2);
    g->insert_edge(1, 3);
    g->insert_edge(2, 4);
    g->insert_edge(3, 4);
    g->insert_edge(4, 5);
    
    std::cout << "Исходный граф:\n";
    print_graph(g, 5);
    
    Graph* gt = g->transpose();
    
    std::cout << "\nТранспонированный граф:\n";
    std::cout << "(все рёбра развёрнуты в обратном направлении)\n";
    print_graph(gt, 5);
    
    std::cout << "\n=== Тест завершён ===\n";
    
    delete g;
    delete gt;
}

int main() {
    test_transpose();
    
    return 0;
}