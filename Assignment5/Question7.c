#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


void d_to_b(int n, int k, int ar[]) {
	for(int x = n-1; x >= 0; x--) {
		int d = k%2;
		ar[x] = d;
		k /= 2;
	}
}

void func(int ar[], int n, int i, int temp[]) {
	if(i == n) {
		for(int x = 0; x < n; x++) 
			printf("%d", temp[x]);
		printf("\n");
		return;
	}
	if(ar[i] == 0) {
		temp[i] = 0;
		func(ar, n, i+1, temp);
		temp[i] = 1;
		func(ar, n, i+1, temp);
	}
	else {
		temp[i] = 1;
		func(ar, n, i+1, temp);
	}
	return;
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, k;
    scanf("%d%d", &n, &k);
    int ar[n];
    d_to_b(n, k, ar);
    int temp[n];
    for(int x = 0; x <= n-1; x++) {
    	temp[x] = 0;
    	// printf("%d", ar[x]);
    }

    func(ar, n, 0, temp);

}