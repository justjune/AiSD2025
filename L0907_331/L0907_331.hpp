#ifndef L0907_331_HPP
#define L0907_331_HPP

#include <vector>

// Структура для представления графа (список смежности)
struct graph {
    std::vector<std::vector<int>> adjacency_list;
};

// Основная структура для генерирования путей в графе
struct ath_data {
    int s;          // исходная вершина
    int t;          // конечная вершина
    graph g;        // граф для поиска путей
};

// Функция для инициализации структуры ath_data
void init_ath_data(ath_data* data, int source, int target, const graph& graph_struct);

void find_all_paths(const ath_data* data);

#endif