#ifndef L0724_273_HPP
#define L0724_273_HPP

#include <vector>

class Graph {
private:
    int nvertices;                              // Количество вершин
    std::vector<std::vector<int>> edges;        // Список смежности

public:
    // Конструктор
    Graph(int n);

    // Добавить ориентированное ребро
    void insert_edge(int x, int y);

    // Транспонирование графа
    Graph* transpose();

    // Получить количество вершин
    int get_nvertices() const;

    // Получить рёбра вершины
    const std::vector<int>& get_edges(int v) const;
};

#endif // L0724_273_HPP
