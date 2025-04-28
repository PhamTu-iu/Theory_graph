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

int element_at(List L, int i){
    return L.data[i-1];
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

int max(int a, int b){
    if(a>b) return a;
    return b;
}
int min(int a, int b){
    if(a<b) return a;
    return b;
}

int d[100];
int main(){
    Graph G;
	int n, u, v, x, i, j;
    freopen("Project_management.txt", "r", stdin);
	scanf("%d", &n);
	init_graph(&G, n+2);
    int alpha=n+1, beta=n+2;
    d[alpha]=0;
    //1. Đọc danh sách công việc
	for(u=1;u<=n;u++){
        scanf("%d", &d[u]);     
        do{
        	scanf("%d", &x);
        	if(x>0) add_edge(&G, x, u);
		}while(x>0);
    }
    //2. Thêm cung nối alpha với các đỉnh có bậc vào =0
    for(u=1;u<=n;u++){
        int deg_neg=0;
        for(x=1;x<=n;x++){
            if(G.A[x][u]>0) deg_neg++;
        }
        if(deg_neg==0) add_edge(&G, alpha, u);
    }
    //3. Thêm cung nối các đỉnh có bậc ra =0 vào beta
    for(u=1;u<=n;u++){
        int deg_pos=0;
        for(v=1;v<=n;v++){
            if(G.A[u][v]>0) deg_pos++;
        }
        if(deg_pos==0) add_edge(&G, u, beta);
    }
    //4.Xếp thứ tự các đỉnh theo giải thuật sắp xếp topo
    List L;
    topo_sort(G, &L);
    //5. Tính t[u] thời điểm sớm nhất
    int t[100];
    t[alpha]=0;
    // alpha chắc chắn đầu danh sach, các đỉnh còn lại từ 2 đến L.size;
    for(j=2;j<=L.size;j++){
        int u=element_at(L, j);
        t[u]=-oo;
        for(x=1;x<=G.n;x++){
            if(adjacent(G, x, u)) t[u]=max(t[u], t[x]+d[x]);
        }
    }
    //6. Tính T[u] thời điểm trễ nhất
    int T[100]; 
    T[beta]=t[beta];
    // beta chắc chắn nằm cuối danh sác, đi ngược lại từ L.size -1 về 1
    for(j=L.size-1;j>=1;j--){
        int u=element_at(L, j);
        T[u]=+oo;
        for(v=1;v<=G.n;v++){
            if(adjacent(G, u, v)) T[u]=min(T[u], T[v]-d[u]);
        }
    }
    printf("Thoi diem som nhat va tre nhat cua tung cong viec\n");
    printf("t[alpha]=%02d   T[alpha]=%02d\n", t[alpha],  T[alpha]);
    for(u=1;u<=n;u++){
    	printf("t[%02d]=%02d   T[%02d]=%02d\n", u, t[u], u, T[u]);
	}
    printf("t[beta]=%02d   T[beta]=%02d\n", t[beta],  T[beta]);
    printf("Cong viec 5 lam vao ngay thứ 17 duoc khong?\n");
    if(t[5]<=17 && 17<=T[5]) printf("YES");
    else printf("NO");
    return 0;
}
