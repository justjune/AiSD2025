#include "L0886_290.hpp"
#include <algorithm>
#include <numeric>

UnionFind::UnionFind(int n) : parent(n), rank(n, 0) {
    std::iota(parent.begin(), parent.end(), 0);
}

int UnionFind::find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void UnionFind::unite(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
        if (rank[root_i] > rank[root_j]) {
            parent[root_j] = root_i;
        }
        else if (rank[root_i] < rank[root_j]) {
            parent[root_i] = root_j;
        }
        else {
            parent[root_j] = root_i;
            rank[root_i]++;
        }
    }
}

bool UnionFind::are_connected(int r, int f) {
    return find(r) == find(f);
}

int kruskal(std::vector<Edge>& edges, int num_vertices) {
    int total_mst_wight = 0;
    UnionFind uf(num_vertices);
    std::sort(edges.begin(), edges.end());
    for (const auto& edge : edges) {
        if (!uf.are_connected(edge.r, edge.f)) {
            total_mst_wight += edge.wight;
            uf.unite(edge.r, edge.f);
        }
    }
    return total_mst_wight;
}