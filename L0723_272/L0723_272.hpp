#ifndef L0723_272_HPP
#define L0723_272_HPP

#include "../L0517_194/L0517_194.hpp"
#include "../L0705_244/L0705_244.hpp"
#include <vector>
#include <stack>

// Типы рёбер при обходе графа
enum EdgeClass {
    TREE,
    BACK,
    FORWARD,
    CROSS
};

class Graph {
private:
    int nvertices;                              // Количество вершин
    std::vector<std::vector<int>> edges;        // Список смежности
    std::vector<bool> discovered;               // Посещённые вершины
    std::vector<bool> processed;                // Обработанные вершины
    std::vector<int> parent;                    // Родители вершин
    std::vector<int> entry_time;                // Время входа
    std::vector<int> exit_time;                 // Время выхода
    int time_counter;                           // Счётчик времени
    std::stack<int> sorted;                     // Стек для топологической сортировки

    // Классификация ребра
    EdgeClass edge_classification(int x, int y);

    // Обработка вершины (ранняя)
    void process_vertex_early(int v);

    // Обработка вершины (поздняя)
    void process_vertex_late(int v);

    // Обработка ребра
    void process_edge(int x, int y);

    // Поиск в глубину из вершины
    void dfs(int v);

public:
    // Конструктор
    Graph(int n);

    // Добавить ориентированное ребро
    void insert_edge(int x, int y);

    // Топологическая сортировка
    void topsort();
};

#endif // L0723_272_HPP
