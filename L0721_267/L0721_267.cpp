#include <iostream>
using namespace std;

const int MAXN = 1000;  // максимум вершин

int parent[MAXN];
int entry_time[MAXN];
int reachable_ancestor[MAXN];
int tree_out_degree[MAXN];

void process_vertex_late(int v) {
    bool root;       // v - корень дерева обхода?
    int time_v;      // самое раннее время достижимости вершины v
    int time_parent; // самое раннее время достижимости вершины parent[v]

    if (parent[v] == -1) { // вершина v — корень?
        if (tree_out_degree[v] > 1) {
            cout << "root articulation vertex: " << v << endl;
        }
        return;
    }

    root = (parent[parent[v]] == -1); // вершина parent[v] — корень?

    if (!root) {
        if (reachable_ancestor[v] == parent[v]) {
            cout << "parent articulation vertex: " << parent[v] << endl;
        }
        if (reachable_ancestor[v] == v) {
            cout << "bridge articulation vertex: " << parent[v] << endl;
            if (tree_out_degree[v] > 0) { // вершина v — не лист?
                cout << "bridge articulation vertex: " << v << endl;
            }
        }
    }

    time_v = entry_time[reachable_ancestor[v]];
    time_parent = entry_time[reachable_ancestor[parent[v]]];

    if (time_v < time_parent) {
        reachable_ancestor[parent[v]] = reachable_ancestor[v];
    }
}

int main() {
    int n = 5; // количество вершин

    // Инициализация массивов
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        entry_time[i] = 0;
        reachable_ancestor[i] = i;
        tree_out_degree[i] = 0;
    }

    // Задаём тестовый граф вручную
    parent[0] = -1; // корень
    parent[1] = 0;
    parent[2] = 1;
    parent[3] = 1;
    parent[4] = 2;

    entry_time[0] = 0;
    entry_time[1] = 1;
    entry_time[2] = 2;
    entry_time[3] = 3;
    entry_time[4] = 4;

    reachable_ancestor[0] = 0;
    reachable_ancestor[1] = 1;
    reachable_ancestor[2] = 2;
    reachable_ancestor[3] = 2;
    reachable_ancestor[4] = 4;

    tree_out_degree[0] = 1;
    tree_out_degree[1] = 2;
    tree_out_degree[2] = 1;
    tree_out_degree[3] = 0;
    tree_out_degree[4] = 0;

    // Запуск проверки для каждой вершины
    for (int i = 0; i < n; i++) {
        process_vertex_late(i);
    }

    return 0;
}
