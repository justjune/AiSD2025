#include <iostream>
#include "L0907_331.hpp"

void test_ath_data() {
    std::cout << "=== Тестирование структуры ath_data ===" << std::endl;

    // Создаем тестовый граф
    graph test_graph;
    test_graph.adjacency_list = {
        {1, 2},     // вершина 0 соединена с 1 и 2
        {0, 2, 3},  // вершина 1 соединена с 0, 2 и 3
        {0, 1},     // вершина 2 соединена с 0 и 1
        {1}         // вершина 3 соединена с 1
    };

    // Инициализируем структуру ath_data
    ath_data data;
    init_ath_data(&data, 0, 3, test_graph);

    // Проверяем корректность инициализации
    std::cout << "Исходная вершина: " << data.s << std::endl;
    std::cout << "Конечная вершина: " << data.t << std::endl;
    std::cout << "Количество вершин в графе: " << data.g.adjacency_list.size() << std::endl;

    // Тестируем поиск путей
    find_all_paths(&data);

    std::cout << "=== Тестирование завершено ===" << std::endl;
}

int main() {
    test_ath_data();
    return 0;
}