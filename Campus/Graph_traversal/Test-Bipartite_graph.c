/*KIỂM TRA ĐỒ THỊ PHÂN ĐÔI*/
//chỉ dành cho đồ thị vô hướng không có chu trình
#include <stdio.h>
#define RED 1
#define BLUE 2
#define NO_COLOR 0
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
    G->A[u][v]=1;
    G->A[v][u]=1;
    G->m++;
}

int adjacent(Graph G, int u, int v){
    return G.A[u][v]>0;
}
int color[100];
int colorize;
void DFS(Graph G, int u, int c){
    color[u]=c;
    int v;
    for(v=1;v<=G.n;v++){
        if(adjacent(G, u, v)){
            if(color[v]==NO_COLOR) DFS(G, v, 3-c);
            else if(color[v]==color[u]) colorize=1;
        }
    }
}

int main(){
    Graph G;
	int n, m, u, v, e;
    freopen("Test-Bipartite_graph.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	init_graph(&G, n);
	for(e=0;e<m;e++){
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}
    for(u=1;u<=n;u++){
        color[u]=NO_COLOR;
    }
    colorize=0;
    for(u=1;u<=n;u++){
        if(color[u]==NO_COLOR){
            DFS(G, u, RED);
        } 
    }
    if(colorize==1) printf("Can Not divided\n");
    else{
        printf("Can divided\n");
        for(u=1;u<=n;u++){
            if(color[u]==RED) printf("%d ", u);
        }
        printf("\n");
        for(u=1;u<=n;u++){
            if(color[u]==BLUE) printf("%d ", u);
        }
    }
}
