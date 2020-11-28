#ifndef GRAPH_STRUCTURE_H
#define GRAPH_STRUCTURE_H

typedef struct edge e;
typedef e* e_t;

typedef struct vertex v;
typedef v* v_t;

typedef struct graph g;
typedef g* g_t;

struct edge{

  int weight;
  int connects_to;

};

struct vertex{

  int v_edge_count;
  int vertex_name;
  e_t edge;
  v_t next_vertex;

};

struct graph{

  int vertex_count;
  int edge_count;
  v_t vertex;
  
};

#endif
