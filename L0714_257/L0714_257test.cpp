#include <iostream>
#include "L0714_257.hpp"

int main() {
    // Создаем граф с 8 вершинами (неориентированный)
    graph g;
    initialize_graph(&g, false);
    g.nvertices = 8;

    // Инициализация списков смежности
    for (int i = 1; i <= g.nvertices; i++) {
        g.edges[i] = nullptr;
        g.degree[i] = 0;
    }
    
    // Добавляем рёбра для создания 3 компонент связности:
    // Компонента 1: вершины 1-2-3-4
    insert_edge(&g, 1, 2, false);
    insert_edge(&g, 2, 3, false);
    insert_edge(&g, 3, 4, false);
    
    // Компонента 2: вершины 5-6
    insert_edge(&g, 5, 6, false);
    
    // Компонента 3: вершины 7-8
    insert_edge(&g, 7, 8, false);
    
    // Вершина 9 будет изолированной (компонента 4)
    g.nvertices = 9; // Добавляем 9-ю вершину
    
    std::cout << "Поиск компонент связности в графе:\n";
    std::cout << "Ожидается 4 компоненты:\n";
    std::cout << "1: 1 2 3 4\n";
    std::cout << "2: 5 6\n";
    std::cout << "3: 7 8\n";
    std::cout << "4: 9\n\n";
    
    std::cout << "Результат работы connected_components:\n";
    connected_components(&g);
    
    // Вторая проверка: пустой граф
    std::cout << "\nПроверка на пустом графе:\n";
    graph empty_g;
    initialize_graph(&empty_g, false);
    empty_g.nvertices = 0;
    std::cout << "Ожидается: ничего (нет вершин)\n";
    std::cout << "Результат: ";
    connected_components(&empty_g);
    
    // Третья проверка: полный граф из 3 вершин
    std::cout << "\nПроверка на полном графе K3:\n";
    graph full_g;
    initialize_graph(&full_g, false);
    full_g.nvertices = 3;
    for (int i = 1; i <= full_g.nvertices; i++) {
        full_g.edges[i] = nullptr;
        full_g.degree[i] = 0;
    }
    insert_edge(&full_g, 1, 2, false);
    insert_edge(&full_g, 1, 3, false);
    insert_edge(&full_g, 2, 3, false);
    
    std::cout << "Ожидается 1 компонента: 1 2 3\n";
    std::cout << "Результат: \n";
    connected_components(&full_g);
    
    // Четвертая проверка: ориентированный граф
    std::cout << "\nПроверка на ориентированном графе:\n";
    graph dir_g;
    initialize_graph(&dir_g, true);
    dir_g.nvertices = 4;
    
    for (int i = 1; i <= dir_g.nvertices; i++) {
        dir_g.edges[i] = nullptr;
        dir_g.degree[i] = 0;
    }
    insert_edge(&dir_g, 1, 2, true);
    insert_edge(&dir_g, 2, 3, true);
    insert_edge(&dir_g, 3, 4, true);
    
    std::cout << "Ожидается 1 компонента (для ориентированного графа BFS найдет все достижимые вершины):\n";
    std::cout << "Результат: \n";
    connected_components(&dir_g);

    
    return 0;
}