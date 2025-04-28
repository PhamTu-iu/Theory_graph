/*THUẬT TOÁN BELLMANFORD CHỈ CHO CÓ HƯỚNG*/
//có thể điều chỉnh để dùng cho vô hướng nhưng lại phức tạp vô cùng
/*Ðon đồ thị có hướng*/
#include <stdio.h>
#define oo 999999
typedef struct{
	int u, v, w;
}Edge;
typedef struct{
	int n, m;
	Edge edges[100];
}Graph;

/*Khởi tạo đồ thị*/

void init_graph(Graph *G, int n){
	G->n=n;
	G->m=0;
}

/*Thêm cung*/
void add_edge(Graph *G, int u, int v, int w){
	G->edges[G->m].u=u;
	G->edges[G->m].v=v;
    G->edges[G->m].w=w;
    G->m++;
}

/*Kiểm tra hai đỉnh kề nhau*/

int adjacent(Graph G, int u, int v){
	int i;
	for(i=0;i<G.m;i++){
		if((G.edges[i].u==u&&G.edges[i].v==v)||(G.edges[i].u==v&&G.edges[i].v==u))
		   return 1;
	}
	return 0;
}
 
int pi[100];
int p[100];
int negative_cycle;

void BellmanFord(Graph G, int s){
    int u, v, w, i,k;
    for(u=1;u<=G.n;u++){
        pi[u]=oo;
    }

    pi[s]=0;
    p[s]=-1;

    for(i=1;i<G.n;i++){
        for(k=0;k<G.m;k++){
            u=G.edges[k].u;
            v=G.edges[k].v;
            w=G.edges[k].w;
            if(pi[u]==oo) continue;
            
            if(pi[u]+w<pi[v]){
                pi[v]=pi[u]+w;
                p[v]=u;
            } 
        }
    }

    // Kiểm tra chu trình âm

    for(k=0;k<G.m;k++){
        u=G.edges[k].u;
        v=G.edges[k].v;
        w=G.edges[k].w;
        if(pi[u]+w<pi[v]){
           negative_cycle=1;
           break;
        } 
    }
}

int main(){
	Graph G;
	int n, m, u, v, w, e;
	freopen("Bellman_Ford.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	init_graph(&G, n);
	for(e=0;e<m;e++){
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
    negative_cycle=0;
    printf("Duyet tu dinh 1\n");
    BellmanFord(G, 1);
    if(negative_cycle==1) printf("Phat hien chu trinh am\n");
    else printf("Khong co chu trinh am\n");
    for(u=1;u<=n;u++){
        printf("pi[%d]=%d, p[%d]=%d\n", u, pi[u], u, p[u]);
    }  
    printf("Duong di den 5\n");
    int path[100];
    int k=0;
    int current=5;
    if(pi[5]==oo){
        printf("Khong co duong di den 5\n");
        return 0;
    }
    while(current!=-1){
        path[k]=current;k++;
        current=p[current];
    }
    for(u=k-1;u>=0;u--){
        printf("%d ", path[u]);
    }
    return 0;
}