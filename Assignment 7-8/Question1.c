#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define int long long int

void max_heapify(int ar[], int i, int N) {
	int left = 2*i;
	int right = 2*i + 1;
	int largest = i;
	if(left <= N && ar[left] > ar[i]) {
		largest = left;
	}
	if(right <= N && ar[right] > ar[largest]) {
		largest = right;
	}

	if(largest != i) {
		int t = ar[i];
		ar[i] = ar[largest];
		ar[largest] = t;
		max_heapify(ar, largest, N);
	}
}

void heapify(int ar[], int N) {
	for(int x = N/2; x >= 1; x--) {
		max_heapify(ar, x, N);
	}
}

int32_t func(int ar[], int N) {
	int r = ar[1];
	ar[1] = r/3;
	max_heapify(ar, 1, N);
	return r;
}

int32_t main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
	int n, d;
	scanf("%lld %lld", &n, &d);
	int ar[n+1];
	for(int x = 1; x <= n; x++) {
		scanf("%lld", &ar[x]);
	}
	heapify(ar, n);
	int s= 0;
	int mod = 1000000007;
	for(int x = 0; x < d; x++) {
		s = (s + func(ar, n)) % mod;
	}
	printf("%lld ", s);
}