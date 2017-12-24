#include <stdio.h>
#include <limits.h>
#define MAX 5000
int graph[MAX][MAX], n;
int mini(int dist[], bool xyz[]){
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < MAX; v++)
     if (xyz[v] == false && dist[v] <= min) {
         min = dist[v], min_index = v;
     }
  
   return min_index;
}
void dijkstra(int graph[MAX][MAX], int source) {
     int dist[MAX];
     bool xyz[MAX];
     for (int i = 0; i < MAX; i++) {
     	dist[i] = INT_MAX, xyz[i] = false;
     }
     dist[source] = 0;
     for (int count = 0; count < MAX-1; count++){
       int u = mini(dist, xyz);
       xyz[u] = true;
       for (int v = 0; v < MAX; v++)
         if (!xyz[v] and graph[u][v] and dist[u] != INT_MAX and dist[u]+graph[u][v] < dist[v]) {
         	dist[v] = dist[u] + 1;
         }
     }
     for (int i = 1; i < n + 1; i++)
      printf("%d ", dist[i]);
}

int main() {
    int m, u, v, s;
	scanf("%d%d", &n, &m);
	while(m--) {
		scanf("%d%d", &u, &v);
		graph[u][v] = 1;
	}
	scanf("%d", &s);
	dijkstra(graph, s);
	
}