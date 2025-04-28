/*KIỂM TRA ĐỒ THỊ LIÊN THÔNG YẾU*/
//đồ thị liên thông yếu có thể là liên thông mạnh
// đồ thị không phải liên thông yếu chắc chắn sẽ không liên thông mạnh
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

int adjacent(Graph G, int u, int v){
    return G.A[u][v]>0;
}
int mark[100];
int count;
void DFS(Graph G, int u){
    mark[u]=1;
    int v;
    for(v=1;v<=G.n;v++){
        if(adjacent(G, u, v) && mark[v]==0) DFS(G, v);
    }
}

int main(){
    Graph G;
	int n, m, u, v, e;
    freopen("Search_graph.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	init_graph(&G, n);
	for(e=0;e<m;e++){
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}
    for(u=1;u<=n;u++){
        mark[u]=0;
    }
    count=0;
    for(u=1;u<=n;u++){
        if(mark[u]==0){
            DFS(G, u);
            count++;
        } 
    }
    if(count==1) printf("Week Connected\n");
    else printf("Not Connected");
}
