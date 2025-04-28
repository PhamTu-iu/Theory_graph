/*THUẬT TOÁN XẾP HẠNG ĐỒ THỊ*/
// dạng đồ thị có hướng
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

void add_edge(Graph *G, int u, int v){
	G->A[u][v]++;
	G->m++;
}

int adjacent(Graph G, int u, int v){
    return G.A[u][v]>0;
}
/*Khai báo danh sách List*/
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
void push_back(List *L,int x){
    L->data[L->size]=x;
    L->size++;
}
int element_at(List L, int i){
    return L.data[i-1];
}
void copy_list(List *L1, List L2){
    int i;
    for(i=0;i<L2.size;i++){
        L1->data[i]=L2.data[i];
    }
    L1->size=L2.size;
}
int r[100];
void rank(Graph G){
    int d[100];
    int u, v, x, i;
    for(u=1;u<=G.n;u++){
        d[u]=0;
        for(x=1;x<=G.n;x++){
            if(G.A[x][u]!=0) d[u]++;
        }
    }

    List L1, L2;
    make_null_list(&L1);
    for(u=1;u<=G.n;u++){
        if(d[u]==0) push_back(&L1, u);
    }

    int k=0;
    while(L1.size>0){
        make_null_list(&L2);
        for(i=1;i<=L1.size;i++){
            int u=element_at(L1, i);
            r[u]=k;
            for(v=1;v<=G.n;v++){
                if(adjacent(G, u, v)){
                    d[v]--;
                    if(d[v]==0) push_back(&L2, v);
                }
            }
        }
        copy_list(&L1, L2);
        k++;
    }
}

int main(){
    Graph G;
    List L;
	int n, m, u, v, e, i;
    freopen("Graph_sort.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	init_graph(&G, n);
	for(e=0;e<m;e++){
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}
    rank(G);
    for(u=1;u<=n;u++){
        printf("%d %d\n",u, r[u]+1);
    }
    return 0;

}
