/*Ðon đồ thị có hướng*/
#include <stdio.h>
typedef struct{
	int u, v;
}Edge;
typedef struct{
	int n, m;
	Edge edges[100];
}Graph;

/*Khởi tạo đồ thị*/

void init_graph(Graph *G, int n){
	G->n=n;
	G->m=0;
}

/*Thêm cung*/
void add_edge(Graph *G, int u, int v){
	G->edges[G->m].u=u;
	G->edges[G->m].v=v;
    G->m++;
}

/*Kiểm tra hai đỉnh kề nhau*/

int adjacent(Graph G, int u, int v){
	int i;
	for(i=0;i<G.m;i++){
		if(G.edges[i].u==u&&G.edges[i].v==v)
		   return 1;
	}
	return 0;
}

/*Tính bậc*/

int deg(Graph G, int u){
	int i, deg=0;
	for(i=0;i<G.m;i++){
		if(G.edges[i].u==u||G.edges[i].v==u)
		   deg++;
	}
	return deg;
}

/*Tính bậc vào*/

int deg_in(Graph G, int u){
	int i, deg=0;
	for(i=0;i<G.m;i++){
		if(G.edges[i].v==u)
		   deg++;
	}
	return deg;
}

/*Tính bậc ra*/

int deg_out(Graph G, int u){
	int i, deg=0;
	for(i=0;i<G.m;i++){
		if(G.edges[i].u==u)
		   deg++;
	}
	return deg;
}

/*In đồ thị*/
void print(Graph G){
	for(int i=0;i<G.m;i++){
         printf("%d %d\n", G.edges[i].u, G.edges[i].v);
	}
}

