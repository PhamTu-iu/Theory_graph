/*ĐƠN ĐỒ THỊ CÓ HƯỚNG - MA TRẬN ĐỈNH - CUNG*/
#include <stdio.h>
#define PREDECESSOR -1// đỉnh trước
#define SUCCESSOR 1 // đỉnh kề 
typedef struct{
	int n, m;
	int A[100][500];//dinh-cung
}Graph;

/*Khởi tạo đồ thị*/

void init_graph(Graph *G, int n){
	G->n=n;
	G->m=0;
	int u, e;
	for(u=1;u<=G->n;u++){
		for(e=0;e<500;e++){
			G->A[u][e]=0;
		}
	}
}

/*Thêm cung*/

void add_edge(Graph *G, int u, int v){
	G->A[u][G->m]=PREDECESSOR;
	G->A[v][G->m]=SUCCESSOR;
	G->m++;
}

/*Kiểm tra kề*/

int adjacent(Graph G, int u, int v){
	int e;
	for(e=0;e<G.m;e++){
		if(G.A[u][e]==PREDECESSOR && G.A[v][e]==SUCCESSOR) return 1;  
	}
	return 0;
}

/*Tính bậc*/

int deg(Graph G, int u){
	int deg=0, e;
    for(e=0;e<G.m;e++){
        if(G.A[u][e]!=0) deg++;
	}
	return deg;
}

/*Tính bậc vào*/

int deg_in(Graph G, int u){
	int deg=0, e;
	for(e=0;e<G.m;e++){
		if(G.A[u][e]==SUCCESSOR) deg++;
	}
	return deg;
}
/*Tính bậc vào*/

int deg_out(Graph G, int u){
	int deg=0, e;
	for(e=0;e<G.m;e++){
		if(G.A[u][e]==PREDECESSOR) deg++;
	}
	return deg;
}

/*In đồ thị*/

void print(Graph G){
	int e, u;
	for(u=1;u<=G.n;u++){
		for(e=0;e<G.m;e++){
			printf("%2d ", G.A[u][e]);
		}
		printf("\n");
	}
}
