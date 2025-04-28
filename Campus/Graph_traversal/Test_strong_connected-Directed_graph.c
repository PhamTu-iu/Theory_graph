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

int min(int a, int b){
    if(a<b) return a;
    return b;
}

int num[100], min_num[100];
int k, count;
Stack S;
int on_stack[100];
void SCC(Graph G, int u){
    num[u]=min_num[u]=k++;
    push(&S, u);
    on_stack[u]=1;
    int v;
    for(v=1;v<=G.n;v++){
       if(adjacent(G, u, v)){
        if(num[v]<0){
            SCC(G, v);
            min_num[u]=min(min_num[u], min_num[v]);
        }
        else if(on_stack[v]){
            min_num[u]=min(min_num[u], num[v]);
        }
       }
    }
    if(num[u]==min_num[u]){
        int w;
        count++;
        do{
            w=top(S);
            pop(&S);
            on_stack[w]=0;
        }while(w!=u);
    }
}
int main(){
    Graph G;
	int n, m, u, v, e;
    freopen("Test_strong_connected-Directed_graph.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	init_graph(&G, n);
	for(e=0;e<m;e++){
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}
    for(u=1;u<=n;u++){
      num[u]=-1;
    }
    k=1;
    count=0;
    make_null_stack(&S);
    for(u=1;u<=n;u++){
        if(num[u]==-1){
            SCC(G, u);
        } 
    }
    if(count==1){
        printf("Strong Connected\n");
    } 
    else printf("Not Strong Connected\n");
    printf("So bo phan lien thong: %d", count);
}
