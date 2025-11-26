#include <iostream>
#include "L098_332.hpp"
#include "L097_331.hpp"

void test_construct_candidates() {
    std::cout << "=== Тестирование construct_candidates ===" << std::endl;
    
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
    
    // Тест 1: k = 0 (начало пути)
    std::cout << "Тест 1: k = 0 (начало пути)" << std::endl;
    int a1[10] = {0};  // массив текущего решения
    int c1[10];        // массив кандидатов
    int nc1;
    
    construct_candidates(a1, 0, &data, c1, &nc1);
    
    std::cout << "Количество кандидатов: " << nc1 << std::endl;
    std::cout << "Кандидаты: ";
    for (int i = 0; i < nc1; i++) {
        std::cout << c1[i] << " ";
    }
    std::cout << std::endl << std::endl;
    
    // Тест 2: k = 1 (уже выбрана начальная вершина 0)
    std::cout << "Тест 2: k = 1 (начальная вершина 0 выбрана)" << std::endl;
    a1[0] = 0;  // начальная вершина
    
    construct_candidates(a1, 1, &data, c1, &nc1);
    
    std::cout << "Количество кандидатов: " << nc1 << std::endl;
    std::cout << "Кандидаты: ";
    for (int i = 0; i < nc1; i++) {
        std::cout << c1[i] << " ";
    }
    std::cout << std::endl << std::endl;
    
    // Тест 3: k = 2 (путь [0, 1], выбираем следующую вершину)
    std::cout << "Тест 3: k = 2 (путь [0, 1])" << std::endl;
    a1[0] = 0;
    a1[1] = 1;
    
    construct_candidates(a1, 2, &data, c1, &nc1);
    
    std::cout << "Количество кандидатов: " << nc1 << std::endl;
    std::cout << "Кандидаты: ";
    for (int i = 0; i < nc1; i++) {
        std::cout << c1[i] << " ";
    }
    std::cout << std::endl << std::endl;
    
    // Тест 4: k = 2 (путь [0, 2], выбираем следующую вершину)
    std::cout << "Тест 4: k = 2 (путь [0, 2])" << std::endl;
    a1[0] = 0;
    a1[1] = 2;
    
    construct_candidates(a1, 2, &data, c1, &nc1);
    
    std::cout << "Количество кандидатов: " << nc1 << std::endl;
    std::cout << "Кандидаты: ";
    for (int i = 0; i < nc1; i++) {
        std::cout << c1[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "=== Тестирование завершено ===" << std::endl;
}

int main() {
    test_construct_candidates();
    return 0;
}