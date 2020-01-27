#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int ar[505][505];
int vis[505][505];
void dfs(int ina, int inb) {
	vis[ina][inb] = 1;
	if(ar[ina+1][inb] == 1 && vis[ina+1][inb] == 0) {
		dfs(ina+1, inb);
	}
	if(ar[ina-1][inb] == 1 && vis[ina-1][inb] == 0) {
		dfs(ina-1, inb);
	}
	if(ar[ina][inb+1] == 1 && vis[ina][inb+1] == 0) {
		dfs(ina, inb+1);
	}
	if(ar[ina][inb-1] == 1 && vis[ina][inb-1] == 0) {
		dfs(ina, inb-1);
	}
}

int main() {
	for (int x = 0; x < 505; x++) {
		for (int y = 0; y < 505; y++) {
			ar[x][y] = 0;
			vis[x][y] = 0;
		}
	}

	int n, m;
	scanf("%d %d", &n, &m);

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			int a;
			scanf("%d",&a);
			if(a == 1)
				ar[x+1][y+1] = 1;
		}
	}

	int ina, inb;
	int fa, fb;
	scanf("%d %d", &ina, &inb);
	scanf("%d %d", &fa, &fb);

	dfs(ina+1, inb+1);

	if(vis[fa+1][fb+1] == 1)
		printf("YES");
	else
		printf("NO");
}