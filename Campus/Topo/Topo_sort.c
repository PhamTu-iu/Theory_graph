/*THUẬT TOÁN SẮP XẾP TOPO*/
// dạng đồ thị có hướng
#include <stdio.h>
#define oo 999999
/*Khai báo cấu trúc đồ thị*/
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

/*khai báo hàng đợi*/

typedef struct{
    int front, rear;
    int data[100];
}Queue;

void make_null_queue(Queue *Q){
    Q->front=0;
    Q->rear=-1;
}

int empty_queue(Queue *Q){
    return Q->front>Q->rear; 
}

void enqueue(Queue *Q, int x){
    Q->rear++;
    Q->data[Q->rear]=x;
}

void dequeue(Queue *Q){
    Q->front++;
}

int front(Queue Q){
    return Q.data[Q.front];
}

/*Topo-sort*/
void topo_sort(Graph G, List *L){
    int d[100];
    int u, x, v;
    for(u=1;u<=G.n;u++){
        d[u]=0;
        for(x=1;x<=G.n;x++){
            if(G.A[x][u]!=0) d[u]++;
        }
    }

    Queue Q;
    make_null_queue(&Q);

    for(u=1;u<=G.n;u++){
        if(d[u]==0) enqueue(&Q, u);
    }

    make_null_list(L);

    while(!empty_queue(&Q)){
        int u=front(Q);dequeue(&Q);
        push_back(L, u);

        for(v=1;v<=G.n;v++){
            if(adjacent(G, u, v)){
            	d[v]--;
                if(d[v]==0 ) enqueue(&Q, v);
			} 
        }
    }
}

int main(){
    Graph G;
    List L;
	int n, m, u, v, e, i;
    freopen("Topo_sort.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	init_graph(&G, n);
	for(e=0;e<m;e++){
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}
    topo_sort(G, &L);
    for(i=0;i<L.size;i++){
        printf("%d\n", L.data[i]);
    }
    return 0;
}
