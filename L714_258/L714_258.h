/*L714_258.h*/
#pragma once
#include "graph.h"
extern bool processed[];    /* which vertices have been processed */
extern bool discovered[];   /* which vertices have been found */
extern int parent[];        /* discovery relation */


void process_vertex_early(int v);
void process_edge(int x, int y);
void connected_components(graph* g);