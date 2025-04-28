/*TÌM LUỒNG CỰC ĐẠI TRÊN MẠNG*/
#include <stdio.h>
#define oo 999999
typedef struct{
    int dir;// -1: -, 1:+ , 0: chua nhan
    int p;
    int sigma;
}Label;
Label labels[100];
typedef struct{
    int n, m;
    int C[100][100];
    int F[100][100];
}Graph;

void init_graph(Graph *G, int n){
    G->n=n;
    G->m=0;
    int u, v;
    for(u=1;u<=G->n;u++){
        for(v=1;v<=G->n;v++){
            G->C[u][v]=0;
            G->F[u][v]=0;
        } 
    }
}

void add_edge(Graph *G, int u, int v, int c){
    G->C[u][v]=c;
    G->m++;
}

int adjacent(Graph G, int u, int v){
    return G.C[u][v]>0;
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

void init_flow(Graph *G){
    int u, v;
    for(u=1;u<=G->n;u++){
        for(v=1;v<=G->n;v++){
            G->F[u][v]=0;
        }
    }
}
int min(int a, int b){
    if(a<b) return a;
    return b;
}
int FordFulkerson(Graph* G, int s, int t) {
    int u, v, x;
    init_flow(G);
    int max_flow = 0;
    Queue Q;
    do {
        for (u = 1; u <= G->n; u++){
            labels[u].dir = 0;
        } 
        labels[s].dir = +1;
        labels[s].p = s;
        labels[s].sigma = oo;

        make_null_queue(&Q);
        enqueue(&Q, s);
        int found = 0;
        while (!empty_queue(Q)) {
            int u = front(Q); dequeue(&Q);
            for (v= 1; v<= G->n; v++) {
                if (G->C[u][v] != 0 && labels[v].dir==0 && G->F[u][v] < G->C[u][v]) {
                    labels[v].dir = +1;
                    labels[v].p = u;
                    labels[v].sigma = min(labels[u].sigma, G->C[u][v] - G->F[u][v]);
                    enqueue(&Q, v);
                }
            }
            for (x = 1; x<= G->n; x++) {
                if (G->C[x][u] != 0 && labels[x].dir==0 && G->F[x][u] > 0) {
                    labels[x].dir = -1;
                    labels[x].p = u;
                    labels[x].sigma = min(labels[u].sigma, G->F[x][u]);
                    enqueue(&Q, x);
                }
            }
            if (labels[t].dir != 0) {
                found = 1;
                break;
            }
        }
        if (found==1) {
            int sigma = labels[t].sigma;
            int u = t;
            while (u != s) {
                int p = labels[u].p;
                if (labels[u].dir > 0)
                    G->F[p][u] += sigma;
                else
                    G->F[u][p] -= sigma;
                u = p;
            }
            max_flow += sigma;
        }
        else break;
    } while (1);
    return max_flow;
}

int main(){
    Graph G;
    int n, m, u, v, e,f ,c;
    freopen("Maximum_flow.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for(e=0;e<m;e++){
        scanf("%d%d%d", &u, &v, &c);
        add_edge(&G, u, v, c);
    }
    int max_flow=FordFulkerson(&G, 1, n);
    printf("Max flow: %d\n", max_flow);
    printf("In lat cat S\n");
    for(u=1;u<=n;u++){
        if(labels[u].dir!=0) printf("%d ", u);
    }
    printf("\n");
    printf("In lat cat T\n");
    for(u=1;u<=n;u++){
        if(labels[u].dir==0) printf("%d ", u);
    }
}
