#include<stdlib.h>

#include "./adjacency_matrix.h"


int ** create_2d_array(int vertex_count){
 
  int **matrix = malloc(vertex_count * sizeof(int *)); 
  
  for (int i=0; i<vertex_count; i++) 
    matrix[i] = (int *)malloc(vertex_count * sizeof(int)); 

  return matrix;

}

int** create_adjacency_matrix(g_t graph){

  int** matrix = create_2d_array(graph->vertex_count);

  for(int row =0 ; row < graph->vertex_count ; row++){
    for(int col= 0; col < graph->vertex_count ; col++){

      if(row == col){
	matrix[row][col] = 0;
      }
      else {
	int flag = 0;
	for(int z=0; z < graph->vertex[row].v_edge_count ;z++){
	  if(graph->vertex[row].edge[z].connects_to  == graph->vertex[col].vertex_name){
	    matrix[row][col] = 1;
	    flag = 1;
	  }
	}
	if (!flag)
	   matrix[row][col] = 0;
	  
      }
      
    }
  }    
  return matrix;
  
}
