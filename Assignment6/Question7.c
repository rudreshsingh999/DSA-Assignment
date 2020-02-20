#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int min(int x, int y) {
	return x < y ? x : y;
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);
    int ar[n][n];
    for (int x = 0; x < n; x++) {
    	for(int y = 0; y < n; y++) {
    		ar[x][y] = 10000000;
    		if(x == y)
    			ar[x][y] = 0;
    	}
    }

    for(int x = 0; x < n-1; x++) {
    	int a, b, c;
    	scanf("%d %d %d", &a, &b, &c);
    	ar[a][b] = c;
    	ar[b][a] = c;
    }

    int r, k;
    scanf("%d%d", &r, &k);

    int leaf[n];
    int i = 0;
    for(int x = 0; x < n; x++) {
        int c = 0;
        for(int y = 0; y < n; y++) {
            if(ar[x][y] != 10000000 && x != y) {
                c++;
            }
        }
        if(c == 1) {
            leaf[i++] = x;
        }
    }

    for(int x = 0; x < n; x++) {
    	for(int y = 0; y < n; y++) {
    		for(int z = 0; z < n; z++) {
    			ar[y][z] = min(ar[y][z], ar[y][x] + ar[x][z]);
    			ar[z][y] = ar[y][z];
    		}
    	}
    }
    int flag = 0;
    for(int x = 0; x < n; x++) {
    	if(ar[r][x] <= k) {
    		// print only the leaf nodes
            for(int y = 0; y < i; y++) {
                if(leaf[y] == x) {
                    printf("%d ", x);
                    flag = 1;
                }
            }
    	}
    }

    if(flag == 0)
        printf("MEOW");
}