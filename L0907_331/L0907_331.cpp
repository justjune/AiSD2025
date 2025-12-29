//L0907_331
//Структура для генерирования путей в графе
//Иванова Мария ПМ-201
#include <iostream>
#include "L0907_331.hpp"

void init_ath_data(ath_data* data, int source, int target, const graph& graph_struct) {
    data->s = source;
    data->t = target;
    data->g = graph_struct;
}

void find_all_paths(const ath_data* data) {
    std::cout << "Поиск всех путей от вершины " << data->s 
              << " к вершине " << data->t << std::endl;
    std::cout << "Граф содержит " << data->g.adjacency_list.size() 
              << " вершин" << std::endl;
}
