#include <stdio.h>
//#include "Libary_Edge_list_of_a_multi_undirected_graph.c"
//#include "Libary_Matrix_of_a_multi_undirected_graph.c"
//#include "Libary_Vertex_edge_matrix_of_a_multi_undirected_graph.c"
#include "Libary_Vertex_edge_matrix_of_a_multi_undirected_graph.c"
int main(){
	Graph G;
	int n, m, u, v, e;
	freopen("Multi_undirected_graph.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	init_graph(&G, n);
	for(e=0;e<m;e++){
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}
	printf("In do thi\n");
	print(G);
	printf("In so bac\n");
	for(u=1;u<=n;u++){
		printf("%d: %d\n", u, deg(G, u));
	}
	printf("Liet ke so dinh ke\n");
	for(u=1;u<=n;u++){
		printf("%d: ", u);
		for(v=1;v<=G.n;v++){
			if(adjacent(G, u, v)) printf("%d ", v);
		}
		printf("\n");
	}
	return 0;
}
