#include "L0804_287.h"

int main() {
    graph g;
    
    initialize_graph(&g, false);
    g.nvertices = 6;

    insert_edge(&g, 1, 2, 6, false);
    insert_edge(&g, 1, 3, 1, false);
    insert_edge(&g, 1, 4, 5, false);
    insert_edge(&g, 2, 3, 5, false);
    insert_edge(&g, 2, 5, 3, false);
    insert_edge(&g, 3, 4, 5, false);
    insert_edge(&g, 3, 5, 6, false);
    insert_edge(&g, 3, 6, 4, false);
    insert_edge(&g, 4, 6, 2, false);
    insert_edge(&g, 5, 6, 6, false);

    int total_weight = prim(&g, 1);
    std::cout << "Weight of the minimum spanning tree: " << total_weight << "\n";
    
    for (int i = 1; i <= g.nvertices; i++) {
        edgenode* p = g.edges[i];
        while (p != nullptr) {
            edgenode* temp = p;
            p = p->next;
            delete temp;
        }
    }
    
    return 0;
}
