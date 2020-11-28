#ifndef GRAPH_H
#define GRAPH_H

#include "graph_structure.h"

#define IS_MEMORY_ALLOCATED(ptr)				\
  if ((ptr) == NULL) {						\
    perror("MALLOC() ERROR: MEMORY CANNOT BE ALLOCATED !!!\n");	\
  }

g_t create_graph();


void add_vertex(g_t graph, int vertex_name);


void add_edge(g_t graph, int from,  int weight, int to);

/* TODO: to be optimised */
v_t find_vertex(g_t grpah, int vertex_name);

#endif
