#ifndef L0886_290_HPP
#define L0886_290_HPP

#include <vector>

struct Edge {
    int r, f;        // Вершины ребра
    int wight;       // Вес ребра
    bool operator<(const Edge& other) const {
        return wight < other.wight;
    }
};

class UnionFind {
    std::vector<int> parent;
    std::vector<int> rank;
public:
    UnionFind(int n);
    int find(int i);
    void unite(int i, int j);
    bool are_connected(int r, int f);
};

int kruskal(std::vector<Edge>& edges, int num_vertices);

#endif