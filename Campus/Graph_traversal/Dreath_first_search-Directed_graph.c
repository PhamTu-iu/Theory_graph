/*DUYỆT TOÀN BỘ ĐỒ THỊ THEO CHIỀU SÂU CHO ĐỒ VÔ HƯỚNG CÓ KHUYÊN*/
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
/*Khai báo hàng đợi*/

typedef struct{
    int idx;
    int data[100];
}Stack;

void make_null_stack(Stack *S){
    S->idx=-1;
}

int empty_stack(Stack *S){
    return S->idx==-1; 
}

void push(Stack *S, int x){
    S->idx++;
    S->data[S->idx]=x;
}

void pop(Stack *S){
    S->idx--;
}

int top(Stack S){
    return S.data[S.idx];
}


int mark[100];
void DFS(Graph G, int s){
    Stack Q;
    make_null_stack(&Q);
    push(&Q, s);
    while(!empty_stack(&Q)){
        int u=top(Q); pop(&Q);
        if(mark[u]!=0)
           continue;
        printf("%d\n",u);
        mark[u]=1;
        int v;
        for(v=1;v<=G.n;v++){
            if(adjacent(G, u, v)){
                push(&Q, v);
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
            DFS(G, u);
        } 
    }
}
