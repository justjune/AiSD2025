#ifndef L0705_244_HPP
#define L0705_244_HPP

#include <vector>

struct EdgeNode {
    int y;
    int weight;
    EdgeNode* next;
};

struct Graph {
    int nvertices;
    int nedges;
    bool directed;
    std::vector<EdgeNode*> edges;
    std::vector<int> degree;

    // Конструктор
    Graph(int n) : nvertices(n), nedges(0), edges(n + 1, nullptr), degree(n + 1, 0) {}
    ~Graph() {
        for (auto edge : edges) {
            while (edge) {
                EdgeNode* temp = edge;
                edge = edge->next;
                delete temp;
            }
        }
    }
};

// Объявление функций
void insert_edge(Graph* g, int x, int y, bool directed);
void print_graph(const Graph* g);

#endif // L0705_244_HPP
