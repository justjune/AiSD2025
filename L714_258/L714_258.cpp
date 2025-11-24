/*L714_258.cpp*/
#include <stdio.h>
#include <stdbool.h>

#include "bfs-dfs.h"

extern bool processed[];    
extern bool discovered[];  
extern int parent[];       


void connected_components(graph* g) {
    int c;            
    int i;

    initialize_search(g);

    c = 0;
    for (i = 1; i <= g->nvertices; i++) {
        if (!discovered[i]) {
            c = c + 1;
            printf("Component %d:", c);
            bfs(g, i);
            printf("\n");
        }
    }
}
void process_vertex_early(int v) {
    printf(" %d", v);
}



void process_edge(int x, int y) {

}


