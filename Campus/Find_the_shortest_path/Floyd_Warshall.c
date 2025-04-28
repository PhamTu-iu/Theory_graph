/*THUẬT TOÁN FLOYD-WARSHALL TÌM ĐƯỜNG ĐI NGẮN NHẤT CHO ĐỒ THỊ VÔ HƯỚNG VÀ CÓ HƯỚNG*/
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
	G->A[v][u]=w; // vô hướng, có hướng thì bỏ dòng này
	G->m++;
}
int pi[100][100];
int next[100][100];
int negative_cycle;

void FloydWarshall(Graph G){
    int u, v, k;
    for(u=1;u<=G.n;u++){
    	for(v=1;v<=G.n;v++){
    		pi[u][v]=oo;
    		next[u][v]=-1;
		}
	}

    for(u=1;u<=G.n;u++){
    	pi[u][u]=0;
	}
	
	
	
	for(u=1;u<=G.n;u++){
    	for(v=1;v<=G.n;v++){
    		if(G.A[u][v]!=0){
    			pi[u][v]=G.A[u][v];
    			next[u][v]=v;
			}
		}
	}
    
    for(k=1;k<=G.n;k++){
        for(u=1;u<=G.n;u++){
            for(v=1;v<=G.n;v++){
            	if(pi[u][k]!=oo && pi[k][v]!=oo){
            		if(pi[u][k]+pi[k][v]<pi[u][v]){
					    pi[u][v]=pi[u][k]+pi[k][v];
            		    next[u][v]=next[u][k];
				   }
				}			
			}
	    }
    }

    // Kiểm tra chu trình âm

    for(u=1;u<=G.n;u++){
        if(pi[u][u]<0){
            negative_cycle=1;
            break;
        }
    }
}

int main(){
    Graph G;
    int n, m, u, v, w, e;
    freopen("Floyd_Warshall.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for(e=0;e<m;e++){
    	scanf("%d%d%d", &u, &v, &w);
    	add_edge(&G, u, v, w);
	}
	negative_cycle=0;
	FloydWarshall(G);
	if(negative_cycle==1) printf("Co chu trinh am\n");
	else printf("Khong co chu trinh am\n");
	printf("Khoang cach ngan nhat tu u den v\n");
	
	for(u=1;u<=n;u++){
		for(v=1;v<=n;v++){
			printf("%d ", pi[u][v]);
		}
		printf("\n");
	}
	
	printf("Khoang canh ngan nhat tu 1 den v\n");
	for(v=1;v<=n;v++){
			printf("%d ", pi[1][v]);
	}
	printf("\n");
	
}
	
