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
    G->A[u][v]++;
    G->m++;
}

/*Kiểm tra hai đỉnh kề*/

int adjacent(Graph G, int u, int v){
    return G.A[u][v]>0;
}

/*Tính số bậc*/

int deg(Graph G, int u){
    int deg=0, v, x;
    for(v=1;v<=G.n;v++){
        deg+=G.A[u][v];
    }
    for(x=1;x<=G.n;x++){
        deg+=G.A[x][u];
    }
    return deg;
}

/*Tính số bậc vào*/

int deg_in(Graph G, int u){
    int deg=0, x;
    for(x=1;x<=G.n;x++){
        deg+=G.A[x][u];
    }
    return deg;
}

/*Tính số bậc ra*/

int deg_out(Graph G, int u){
    int deg=0, v;
    for(v=1;v<=G.n;v++){
        deg+=G.A[u][v];
    }
    return deg;
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
