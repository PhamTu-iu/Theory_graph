/*ĐA ĐỒ THỊ VÔ HƯỚNG - MA TRẬN ĐỈNH - CUNG*/
#include <stdio.h>
#define LOOP 2 //khuyên
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
    if(u==v) G->A[u][G->m]=LOOP;
    else{
        G->A[u][G->m]++;
	    G->A[v][G->m]++;
    }
	G->m++;
}

/*Kiểm tra kề*/

int adjacent(Graph G, int u, int v){
	int e;
    if(u==v){// kiểm tra khuyên
        for(e=0;e<G.m;e++){
             if(G.A[u][e]==LOOP) return 1;
        }
    }
    else{
        for(e=0;e<G.m;e++){
            if(G.A[u][e]!=0 && G.A[v][e]!=0) return 1;  
        }
    }
	return 0;
}

/*Tính bậc*/

int deg(Graph G, int u){
	int deg=0, e;
    for(e=0;e<G.m;e++){
        if(G.A[u][e]==LOOP) deg+=2;
        else if(G.A[u][e]!=0) deg++;
	}
	return deg;
}

/*In đồ thị*/

void print(Graph G){
	int e, u;
	for(u=1;u<=G.n;u++){
		for(e=0;e<G.m;e++){
			printf("%d ", G.A[u][e]);
		}
		printf("\n");
	}
}
