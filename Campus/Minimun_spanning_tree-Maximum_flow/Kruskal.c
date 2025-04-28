/*THUẬT TOÁN KRUSKAL*/
// chỉ dùng cho đồ thị vô hướng
#include <stdio.h>
typedef struct{
	int u, v, w;
}Edge;
typedef struct{
	int n, m;
	Edge edges[100];
}Graph;

void init_graph(Graph *G, int n){
	G->n=n;
	G->m=0;
}

void add_edge(Graph *G, int u, int v, int w){
	G->edges[G->m].u=u;
	G->edges[G->m].v=v;
    G->edges[G->m].w=w;
    G->m++;
}

int adjacent(Graph G, int u, int v){
	int i;
	for(i=0;i<G.m;i++){
		if((G.edges[i].u==u&&G.edges[i].v==v)||(G.edges[i].u==v&&G.edges[i].v==u))
		   return 1;
	}
	return 0;
}

int parent[100];
int findRoot(int u){
    while(parent[u]!=u){
        u=parent[u];
    }
    return u;
}

void Swap(Edge *x, Edge *y){
    Edge temp=*x;
    *x=*y;
    *y=temp;
}
int Kruskal(Graph *G, Graph *T){
    int u, v, w, e, i, j;
    for(i=0;i<G->m;i++){
        for(j=i+1;j<G->m;j++){
            if(G->edges[j].w<G->edges[i].w){
                Swap(&G->edges[j], &G->edges[i]);
            }
        }
    }
    init_graph(T, G->n);
    for(u=1;u<=G->n;u++){
        parent[u]=u;
    }
    int sum_w=0;

    for(e=0;e<G->m;e++){
        u=G->edges[e].u;
        v=G->edges[e].v;
        w=G->edges[e].w;
        int root_u=findRoot(u);
        int root_v=findRoot(v);
        if(root_u!=root_v){
            add_edge(T, u, v, w);
            parent[root_v]=root_u;
            sum_w+=w;
        }
    }
    return sum_w;
}
int main(){
    Graph G, T;
	int n, m, u, v, w, e;
	freopen("Kruskal.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	init_graph(&G, n);
	for(e=0;e<m;e++){
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
    int sum_w=Kruskal(&G, &T);
    printf("Tong trong so cay khung nho nhat: %d\n", sum_w);
    printf("Cac bo phan cay khung\n");
    for(e=0;e<T.m;e++){
        if(T.edges[e].u>T.edges[e].v) printf("(%d, %d): %d\n", T.edges[e].v, T.edges[e].u, T.edges[e].w);
        else printf("(%d, %d): %d\n", T.edges[e].u, T.edges[e].v, T.edges[e].w);
    }
    return 0;
}