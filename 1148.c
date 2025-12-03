#include <stdio.h>
#include <string.h>

#define MAXN 501
#define INF 1000000000

int mat[MAXN][MAXN];

int dijkstra(int n, int src, int dest) {
    int dist[MAXN], vis[MAXN];
    int i, j;
    for (i = 0; i < n; i++) { dist[i] = INF; vis[i] = 0; }
    dist[src] = 0;

    for (i = 0; i < n; i++) {
        int u = -1, best = INF;
        for (j = 0; j < n; j++) {
            if (!vis[j] && dist[j] < best) { best = dist[j]; u = j; }
        }
        if (u == -1) break;
        if (u == dest) break;
        vis[u] = 1;
        for (j = 0; j < n; j++) {
            if (!vis[j] && mat[u][j] != INF) {
                if (dist[u] + mat[u][j] < dist[j]) dist[j] = dist[u] + mat[u][j];
            }
        }
    }

    if (dist[dest] >= INF) return -1;
    return dist[dest];
}

int main() {
    int n, e;
    while (scanf("%d %d", &n, &e) == 2 && (n || e)) {
        int i, j;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                mat[i][j] = INF;

        for (i = 0; i < e; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            u--; v--;
            if (mat[v][u] != INF) {
                
                mat[u][v] = 0;
                mat[v][u] = 0;
            } else {
                if (w < mat[u][v]) mat[u][v] = w; 
            }
        }

        int q;
        scanf("%d", &q);
        for (i = 0; i < q; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            int ans = dijkstra(n, a - 1, b - 1);
            if (ans == -1) printf("Nao e possivel entregar a carta\n");
            else printf("%d\n", ans);
        }
        printf("\n");
    }
    return 0;
}
