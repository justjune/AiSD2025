//L724_273
//Транспонирование графа
//Гаврилюк Екатерина, МЕН-243201 (ПМ-201) 11.11.2025
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
public:
    int nvertices;                 // число вершин
    bool directed;                 // ориентированный граф
    vector<list<int>> edges;       // списки смежности

    Graph(int n, bool dir) : nvertices(n), directed(dir), edges(n + 1) {}

    void insert_edge(int x, int y, bool dir) {
        edges[x].push_back(y);
        if (!dir)
            edges[y].push_back(x);
    }

    Graph transpose() const {
        Graph gt(nvertices, true);
        for (int x = 1; x <= nvertices; x++) {
            for (int y : edges[x]) {
                gt.insert_edge(y, x, true); // обратное направление
            }
        }
        return gt;
    }

    void print() const {
        for (int i = 1; i <= nvertices; i++) {
            cout << i << ": ";
            for (int y : edges[i]) cout << y << " ";
            cout << endl;
        }
    }
};
