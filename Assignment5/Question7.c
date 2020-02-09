#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    scanf("%d%d", &n, &m);
    int ar[n][m];

    for(int x = 0; x < n; x++) {
    	for(int y = 0; y < m; y++) {
    		scanf("%d", &ar[x][y]);
    	}
    }
    int r;
    scanf("%d", &r);
    int l = 0;
    int h = n-1;

    while(l <= h) {
    	int mid = (l+h)/2;
    	if(ar[mid][m-1] < r) {
    		l = mid + 1;
    	}
    	else {
    		h = mid - 1;
    	}
    }
    int i = -1;
    for (int x = 0; x < m; x++) {
    	if(ar[l][x] == r) {
    		i = x;
    		break;
    	}
    }
    if(i == -1) 
    	printf("MISSING");
    else
    	printf("YES\n%d %d\n", l, i);
}