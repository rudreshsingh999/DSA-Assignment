#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int * ptr[1000];
int size[1000];
int vis[1000];
void dfs(int n) {
    vis[n] = 1;
    for(int x = 0; x < size[n]-1; x++) {
        if(vis[ptr[n][x]] == 0)
            dfs(ptr[n][x]);
    }
    printf("%d ", n);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    scanf("%d%d", &n, &m);
    // int * ptr[n+1];
    // int size[n+1];
    for(int x = 0; x <= n; x++) {
        ptr[x] = (int *)(calloc(1,sizeof(int)));
        size[x] = 1;
    }
    int in[n+1];
    for(int x = 0; x <= n; x++)
        in[x] = 0;

    for (int x = 0; x < m; x++) {
        int a, b;
        scanf("%d %d", &a, &b);
        ptr[b][size[b]-1] = a;
        ptr[b] = realloc(ptr[b], size[b] + 1);
        size[b]++;
        in[a]++;
    }

    for(int x = 0; x <= n ; x++) {
        vis[x] = 0;
    }

    int i;
    for(int x = 1; x <= n; x++) {
        if(in[x] == 0) {
            i = x;
            break;
        }

    }
    // Print in reverse order
    dfs(i);
    printf("\n");
}