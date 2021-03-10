#include<stdio.h>
#include <stdlib.h>

#include "graph.h"


g_t create_graph(){

  g_t new_graph  = malloc(sizeof(g));

  /* check for allocation from malloc */
  IS_MEMORY_ALLOCATED(new_graph);

  /* set to initial values */
  new_graph->vertex_count = 0;
  new_graph->edge_count = 0;
  new_graph->vertex = NULL;
  return new_graph;
}


v_t find_vertex(g_t graph, int vertex_name){
  for(int i = 0; i < graph->vertex_count; i++){
    if(graph->vertex[i].vertex_name == vertex_name){
      return &graph->vertex[i];
    }
  }
  return NULL;
}


void add_vertex(g_t g, int vertex_name){
  
  v_t new_vertex =  malloc(sizeof(v));
  IS_MEMORY_ALLOCATED(new_vertex);
    
  new_vertex->vertex_name =  vertex_name;
  new_vertex->edge = NULL;
  new_vertex->next_vertex = NULL;
  new_vertex->v_edge_count =0;

  /* check if it's the first node in the graph */
  if(g->vertex_count == 0){
    g->vertex = malloc(sizeof(v));
    IS_MEMORY_ALLOCATED(g->vertex);
    g->vertex[0] = *new_vertex;
  }
  
  else{
    g->vertex = realloc( g->vertex, sizeof(v) * (g->vertex_count + 1));
    IS_MEMORY_ALLOCATED(g->vertex);
    g->vertex[g->vertex_count] = *new_vertex;
  }
  
  g->vertex_count++;

}

void add_edge(g_t g, int from, int weight, int to){
  
  e_t new_edge = malloc(sizeof(e));
  IS_MEMORY_ALLOCATED(new_edge);

  new_edge->weight = weight;
  new_edge->connects_to = to;
  
  /* TODO::: optimise the finding of a vertex in graph */
  v_t from_vertex = find_vertex(g, from);
  
  if(from_vertex == NULL){
    printf("No such node named \"%d\" found", from); 
  }

  /* check if its the first edge from the from node */
  if(from_vertex->v_edge_count == 0){
    from_vertex->edge =  malloc(sizeof(e));
    IS_MEMORY_ALLOCATED(from_vertex->edge);
    
    from_vertex->edge[0] = *new_edge;
  }
  
  else{
    from_vertex->edge = realloc( from_vertex->edge, sizeof(e) * (from_vertex->v_edge_count+1));
    IS_MEMORY_ALLOCATED(from_vertex->edge);  
    from_vertex->edge[from_vertex->v_edge_count] = *new_edge;
  }
  
  from_vertex->v_edge_count++;
  g->edge_count++;
  
}
