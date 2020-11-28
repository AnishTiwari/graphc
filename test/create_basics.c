#include "../graph.c"

#include "../adjacency_matrix.c"

void print_matrix(int** mat, int r, int c){
  for(int i = 0; i < r; i++){
    for(int j=0 ; j < c; j++){
      printf("%d \t",mat[i][j]);
    }
	printf("\n");
  }


			     

}

int main(){

  /* creating a linear chain graph 
   * 1-(20)-> 2-(30)-> 3 
   */
  g_t my_graph =  create_graph();

  /* add nodes */
  add_vertex(my_graph, 1);
  add_vertex(my_graph, 2);
  add_vertex(my_graph, 3);

  /* add edges */
  add_edge(my_graph, 1, 20, 2);
  add_edge(my_graph, 2, 30, 3);  

  /* printf adjacency mateix */
  int** matrix = create_adjacency_matrix(my_graph);
  print_matrix(matrix, 3, 3);
    
  return 0;
}
