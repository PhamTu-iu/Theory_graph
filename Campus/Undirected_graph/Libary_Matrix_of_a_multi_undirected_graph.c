/*Đơn ĐỒ THỊ CÓ HƯỚNG - MA TRẬN KỀ(ĐỈNH ĐỈNH)*/
#include <stdio.h>
typedef struct{
    int n, m;
    int A[100][100];
}Graph;

/*Khởi tạo đồ thị*/

void init_graph(Graph *G, int n){
    G->n=n;
    G->m=0;
    int u, v;
    for(u=1;u<=G->n;u++){
        for(v=1;v<=G->n;v++){
            G->A[u][v]=0;
        }
    }
}

/*Thêm cạnh*/

void add_edge(Graph *G, int u, int v){
	if(u==v) G->A[u][u]++;
    else{
    	G->A[u][v]++;
        G->A[v][u]++;
	}
    G->m++;
}

/*Kiểm tra hai đỉnh kề*/

int adjacent(Graph G, int u, int v){
    return G.A[u][v]>0;
}

/*Tính số bậc*/

int deg(Graph G, int u){
    int deg=0, v;
    for(v=1;v<=G.n;v++){
         deg+=G.A[u][v];
    }
    return deg+=G.A[u][u];
}

/*In đồ thị*/

void print(Graph G){
    int u, v;
    for(u=1;u<=G.n;u++){
        for(v=1;v<=G.n;v++){
            printf("%d ", G.A[u][v]);
        }
        printf("\n");
    }
}
