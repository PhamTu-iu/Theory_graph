/*DUYỆT TOÀN BỘ ĐỒ THỊ THEO CHIỀU RỘNG CHO ĐỒ VÔ HƯỚNG CÓ KHUYÊN*/
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
/*Khai báo hàng đợi*/

typedef struct{
    int front, rear;
    int data[100];
}Queue;

void make_null_queue(Queue *Q){
    Q->front=0;
    Q->rear=-1;
}

int empty_queue(Queue Q){
    return Q.front>Q.rear; 
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


int mark[100];
void BFS(Graph G, int s){
    Queue Q;
    make_null_queue(&Q);
    enqueue(&Q, s);
    while(!empty_queue(Q)){
        int u=front(Q); dequeue(&Q);
        if(mark[u]!=0)
           continue;
        printf("%d\n",u);
        mark[u]=1;
        int v;
        for(v=1;v<=G.n;v++){
            if(adjacent(G, u, v)){
                enqueue(&Q, v);
            }
        }
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
    for(u=1;u<=n;u++){
        if(mark[u]==0){
            BFS(G, u);
        } 
    }
}
