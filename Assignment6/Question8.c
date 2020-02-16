#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);

    int ar[n];
    for(int x = 0; x < n; x++) {
    	scanf("%d", &ar[x]);
    }

    int stack[n];
    int i = -1;
    int max_area = 0;
    for(int x = 0; x < n; x++) {
    	if(i == -1) {
    		stack[++i] = x;
    	}
    	else {
    		if(ar[x] >= ar[stack[i]]) {
    			stack[++i] = x;
    		}
    		else {
    			while(i != -1 && ar[x] < ar[stack[i]]) {
    				int r = stack[i--];
    				int area;
    				if(i != -1)
    					area = ar[r] * (x - stack[i] - 1);
    				else
    					area = ar[r] * x;

    				if(area > max_area)
    					max_area = area;
    			}
    			stack[++i] = x;
    		}
    	}
    }

    while(i != -1) {
    	int r = stack[i--];
    	int area;
    	if(i != -1)
    		area = ar[r] * (n - stack[i] - 1);
    	else 
    		area = ar[r] * n;

    	if(area > max_area) 
    		max_area = area;
    }

    printf("%d", max_area);
}