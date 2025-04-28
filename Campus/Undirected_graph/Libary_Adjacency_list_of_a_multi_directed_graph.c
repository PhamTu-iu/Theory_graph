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
    if(u==v) {
        insert(&(G->L[u]), u);
    }
    else{
        insert(&(G->L[u]), v);
        insert(&(G->L[v]), u);
    }
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
    int i, x, deg=0;
    for(i=0; i<G.L[x].size;i++){ // từng chỉ số
            if(G.L[x].data[i]==u) deg++; // tìm khuyên
    }
    return deg+G.L[u].size;
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
