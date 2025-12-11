//L0724_273
//Транспонирование графа
//Гаврилюк Екатерина, МЕН-243201 (ПМ-201) 11.11.2025
#include "L0724_273.hpp"

// Конструктор
Graph::Graph(int n) : nvertices(n) {
    edges.resize(n + 1);
}

// Добавить ориентированное ребро
void Graph::insert_edge(int x, int y) {
    edges[x].push_back(y);
}

// Получить количество вершин
int Graph::get_nvertices() const {
    return nvertices;
}

// Получить рёбра вершины
const std::vector<int>& Graph::get_edges(int v) const {
    return edges[v];
}

// Транспонирование графа
Graph* Graph::transpose() {
    Graph* gt = new Graph(nvertices);  // Создать новый граф с тем же количеством вершин

    // Перебрать все вершины
    for (int x = 1; x <= nvertices; x++) {
        // Для каждого ребра x->y добавить обратное ребро y->x
        for (int y : edges[x]) {
            gt->insert_edge(y, x);
        }
    }

    return gt;  // Вернуть транспонированный граф
}
