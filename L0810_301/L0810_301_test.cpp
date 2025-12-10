#include "L0810_301.hpp"
#include <iostream>
using namespace std;

void delete_list(edgenode* node) {
    if (node == nullptr) return;
    delete_list(node->link);  
    delete node;             
}

int main() {
    graph g;
    
    make_graph(&g, false);
    
    //Количество вершин
    g.nodes = 5;
    
    //Добавляем ребра
    add_edge(&g, 1, 2, 10, false);
    add_edge(&g, 1, 3, 3, false);
    add_edge(&g, 2, 3, 1, false);
    add_edge(&g, 2, 4, 2, false);
    add_edge(&g, 3, 4, 8, false);
    add_edge(&g, 3, 5, 2, false);
    add_edge(&g, 4, 5, 7, false);
    
    int total = shortest(&g, 1);
    
    cout << "\nОбщий вес дерева: " << total << endl;
    
    for (int i = 1; i <= g.nodes; i++) {
        delete_list(g.list[i]);
        g.list[i] = nullptr;
    }
    
    return 0;
}
