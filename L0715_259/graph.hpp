#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

class Graph {
private:
    struct Edge {
        int y;
        struct Edge *next;
    };

    vector<Edge*> edges;
    vector<int> degree;
    vector<int> color;
    vector<bool> visited;
    vector<bool> processed;
public:
    int nvertices;
private:
    int nedges;
    bool dir;
    int max_vertices = 100;

    void process_edge(Graph *g, int x, int y);
    void process_vertex_early();
    int rev(int x);

public:
    // Основные методы управления графом
    void init_graph(Graph *g, bool dir);
    void ins_edge(Graph *g, int x, int y, bool dir);
    void read_graph(Graph *g, bool dir);
    void print_graph(Graph *g);

    // Алгоритмы обхода
    void pred_bfs(Graph *g);
    void bfs(Graph *g, int start);

    // Алгоритмы работы с графом
    void two_color(Graph *g);
    void print_color_graph(Graph *g);
};

#endif // GRAPH_H