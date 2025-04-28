/*KIỂM TRA CHU TRÌNH ĐỐI VỚI ĐỒ THỊ CÓ HƯỚNG*/
#include <stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
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
    G->A[v][u]++;
    G->m++;
}

int adjacent(Graph G, int u, int v){
    return G.A[u][v]>0;
}
int has_circle=0;
int color[100];
void DFS(Graph G, int u){
	color[u]=GRAY;
	int v;
	for(v=1;v<=G.n;v++){
		if(adjacent(G, u, v)){
		    if(color[v]==WHITE)
		       DFS(G, v);
		    if(color[v]==GRAY)
		        has_circle=1;
		}
	}
	color[u]=BLACK;
}
int main(){
	Graph G;
	freopen("Test_circle.txt","r", stdin);
	int n, m, u, v,e, i, j;
	scanf("%d %d",&n,&m);
	init_graph(&G, n);
	for(e=1;e<=m;e++){
		scanf("%d %d",&u, &v);
		add_edge(&G, u, v);
	}
	for(u=1;u<=n;u++){
		color[u]=WHITE;
	}
	for(u=1;u<=n;u++){
		if(color[u]==WHITE)
		   DFS(G, u);
	}
	if(has_circle==1) printf("CIRCLE");
	else printf("DISCIRCLE");
	return 0;
}