#ifndef L724_273.HPP
#define L724_273.HPP


#include <iostream>
#include <vector>
#include <list>

class Graph {
private:
    int nvertices;                      // число вершин
    bool directed;                      // ориентированный граф
    std::vector<std::list<int>> edges;  // списки смежности

public:
    // --- Конструктор ---
    Graph(int n, bool dir);

    // --- Методы ---
    void insert_edge(int x, int y, bool dir); // вставка ребра
    Graph transpose() const;                  // транспонирование графа
    void print() const;                       // вывод графа

    int get_vertex_count() const { return nvertices; }
    bool is_directed() const { return directed; }
};

#endif