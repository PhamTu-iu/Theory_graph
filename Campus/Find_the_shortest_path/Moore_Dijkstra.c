/*THUẬT TOÁN MOOREDIJKSTRA TÌM ĐƯỜNG ĐI NGẮN NHẤT CHO ĐỒ THỊ VÔ HƯỚNG VÀ CÓ HƯỚNG*/
#include <stdio.h>
#define oo 999999
typedef struct{
    int n, m;
    int A[100][100];
}Graph;

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

void add_edge(Graph *G, int u, int v, int w){
    G->A[u][v]=w;
    G->A[v][u]=w;// vô hướng- có hướng bỏ dòng này
    G->m++;
}

int adjacent(Graph G, int u, int v){
    return G.A[u][v]>0;
}

int mark[100];
int pi[100];
int p[100];

void MooreDijkstra(Graph G, int s){
    int u, v, i;
    for(u=1;u<=G.n;u++){
        pi[u]=oo;
        mark[u]=0;
    }

    pi[s]=0;
    p[s]=-1;

    for(i=1;i<G.n;i++){
        int j, min_pi=oo;
        for(j=1;j<=G.n;j++){
            if(mark[j]==0 && pi[j]<min_pi){
                min_pi=pi[j];
                u=j;
            }
        }

        mark[u]=1;

        for(v=1;v<=G.n;v++){
            if(mark[v]==0 && adjacent(G, u, v)){
                if(pi[u]+G.A[u][v]<pi[v]){
                    pi[v]=pi[u]+G.A[u][v];
                    p[v]=u;
                }
            }
        }

    }

}
int main(){
    Graph G;
	int n, m, u, v, w, e;
    freopen("Moore_Dijkstra.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	init_graph(&G, n);
	for(e=0;e<m;e++){
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
    printf("Duong di ngan nhat tu dinh 1\n");
    MooreDijkstra(G,1);
    for(u=1;u<=n;u++){
        printf("pi[%d]=%d, p[%d]=%d\n", u, pi[u], u, p[u]);
    }
    printf("Duong di den 5\n");
    int path[100];
    int k=0;
    int current=5;
    while(current!=-1){
        path[k]=current;k++;
        current=p[current];
    }
    for(u=k-1;u>=0;u--){
        printf("%d ", path[u]);
    }
}