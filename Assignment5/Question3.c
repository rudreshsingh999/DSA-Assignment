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
    scanf("%d %d", &n, &m);
    int ar[n];
    for(int x = 0; x < n; x++) {
    	scanf("%d", &ar[x]);
    }
    int ans = 0;
    for(int x = 0; x < n-2; x++) {
    	int l = x+1;
    	int h = n-1;
    	int r = ar[x] + m;
    	while(l <= h) {
    		int mid = (l+h)/2;
    		if(r < ar[mid]) {
    			h = mid - 1;
    		}
    		else {
    			l = mid + 1;
    		}
    	}
    	int s = h - x - 1;
    	ans = ans + (s*(s+1))/2;
    	// printf("%d ", h);
    }
    printf("%d\n",ans);
}