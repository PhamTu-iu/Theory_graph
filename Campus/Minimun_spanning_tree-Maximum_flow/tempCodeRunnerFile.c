/*THUẬT TOÁN MOOREDIJKSTRA TÌM ĐƯỜNG ĐI NGẮN NHẤT CHO ĐỒ THỊ VÔ HƯỚNG VÀ CÓ HƯỚNG*/
// chỉ dùng cho đồ thị vô hướng
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
    G->A[v][u]=w;
    G->m++;
}

int adjacent(Graph G, int u, int v){
    return G.A[u][v]>0;
}

int mark[100];
int pi[100];
int p[100];

int Prim(Graph G, Graph *T, int s){
    int i, u, v, x;
    for(u=1;u<=G.n;u++){
        pi[u]=oo;
        p[u]=-1;
        mark[u]=0;
    }

    pi[s]=0;

    for(i=1;i<G.n;i++){
        int j, min_dist=oo;
        for(x=1;x<=G.n;x++){
            if(mark[x]==0 && pi[x]<min_dist){
                min_dist=pi[x];
                u=x;
            }
        }

        mark[u]=1;

        for(v=1;v<=G.n;v++){
            if(adjacent(G, u, v)){
                if(mark[v]==0 && G.A[u][v]<pi[v]){
                    pi[v]=G.A[u][v];
                    p[v]=u;
                }
            }
        }

    }

    init_graph(T, G.n);
    int sum_w=0;
    for(u=1;u<=G.n;u++){
        if(p[u]!=-1){
            int w=G.A[p[u]][u];
            add_edge(T, p[u], u, w);
            sum_w+=w;
        }
    }
    return sum_w;
}
int main(){
    Graph G, T;
	int n, m, u, v, w, e;
    freopen("Prim.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	init_graph(&G, n);
	for(e=0;e<m;e++){
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}

    int sum_w=Prim(G, &T, 1);
    printf("Tong trong so cay khung toi thieu: %d",sum_w);
    printf("Cac bo phan tao thanh cay khung toi thieu\n");
    for(u=1;u<=T.n;u++){
        for(v=u