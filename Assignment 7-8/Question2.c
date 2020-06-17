#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define int long long int

void initialize(int ar[], int n) {
	for(int x = 0; x < n; x++) {
		ar[x] = x;
	}
}

int root(int i, int ar[]) {
	while(i != ar[i]) {
		ar[i] = ar[ar[i]];
		i = ar[i];
	}
	return i;
}

void unione(int a, int b, int ar[]) {
	int p = root(a, ar);
	int q = root(b, ar);
	ar[p] = ar[q];
}

struct MST {
	int cost;
	int u;
	int v;
};


void merge(int l, int mid, int h, struct MST g[]) {
	struct MST ar1[mid-l+1];
	struct MST ar2[h-mid];
	struct MST ar3[h-l+1];

	for(int x = l; x <= mid; x++) {
		ar1[x-l] = g[x];
	}

	for(int x = mid+1; x <= h; x++) {
		ar2[x-mid-1] = g[x];
		// level2[x-mid-1] = level[x];
	}

	int i = 0, j = 0, k = 0;
	while(i < (mid-l+1) && j < (h-mid)) {
		if(ar1[i].cost <= ar2[j].cost) {
			ar3[k] = ar1[i];
			k++;
			i++;
		}
		else {
			ar3[k] = ar2[j];
			k++;
			j++;
		}
	}

	while(i < (mid-l+1)) { 
		ar3[k] = ar1[i];
		k++;
		i++;
	}

	while(j < (h-mid)) {
		ar3[k] = ar2[j];
		// level3[k] = level2[j];
		k++;
		j++;
	}

	for (int x = l; x <= h; x++) {
		g[x] = ar3[x-l];
		// level[x] = level3[x-l];
	}
}

void merge_sort(int l, int h, struct MST g[]) {
	if(l == h) {
		return;
	}
	int mid = (l + h)/2;
	merge_sort(l, mid, g);
	merge_sort(mid+1, h, g);
	merge(l, mid, h, g);
}

int32_t main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	int n, m;
	scanf("%lld %lld", &n, &m);
	struct MST g[m];
	for(int x = 0; x < m; x++) {
		int a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		g[x].cost = c;
		g[x].u = a;
		g[x].v = b;
	}

	merge_sort(0, m-1, g);
	int ar[n];
	initialize(ar, n);
	int ans = 0;
	for(int x = 0; x < m; x++) {
		if(root(g[x].u, ar) != root(g[x].v, ar)) {
			ans += g[x].cost;
			unione(g[x].u, g[x].v, ar);
		}
	}
	printf("%lld", ans);
}