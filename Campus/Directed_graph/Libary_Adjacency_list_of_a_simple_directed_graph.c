#include <stdio.h>
typedef struct{
    int data[100];
    int size;
}List;
void make_null_list(List *L){
    L->size=0;
}
int empty_list(List L){
    return L.size==0;
}
void insert(List *L,int x){
    L->data[L->size]=x;
    L->size++;
}
typedef struct{
    int n, m;
    List L[100];
}Graph;
void init_graph(Graph *G, int n){
    G->n=n;
    G->m=0;
    int u;
    for(u=1;u<=G->n;u++){
        make_null_list(&(G->L[u]));
    }
}
void add_edge(Graph *G, int u, int v){
    insert(&(G->L[u]), v);
    G->m++;
}
int adjacent(Graph G, int u, int v){
    int i;
    for(i=0;i<G.L[u].size;i++){
        if(G.L[u].data[i]==v) return 1;
    }
    return 0;
}
int deg(Graph G, int u){
    int v, x, i, deg=0;
    for(x=1;x<=G.n;x++){ // chạy từng hàng list
        if(x==u) continue;// x tại u sẽ chứa bậc ra
        for(i=0; i<G.L[x].size;i++){ // từng chỉ số
            if(G.L[x].data[i]==u) deg++; // tổng bậc vào
        }
    }
    return deg+G.L[u].size;
}
int deg_in(Graph G, int u){
    int deg=0, x, i;
    for(x=1;x<=G.n;x++){ // chạy từng hàng list
        if(x==u) continue;// x tại u sẽ chứa bậc ra
        for(i=0; i<G.L[x].size;i++){ // từng chỉ số
            if(G.L[x].data[i]==u) deg++; // tổng bậc vào
        }
    }
    return deg;
}
int deg_out(Graph G, int u){
    return G.L[u].size;
}
void print(Graph G){
    int u, i;
    for(u=1;u<=G.n;u++){
        printf("%d: ", u);
        for(i=0;i<G.L[u].size;i++){
            printf("%d ", G.L[u].data[i]);
        }
        printf("\n");
    }
}
