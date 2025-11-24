/*L714_258.h*/
#pragma once
#include "graph.h"
extern bool processed[];    
extern bool discovered[];   
extern int parent[];        


void process_vertex_early(int v);
void process_edge(int x, int y);
void connected_components(graph* g);