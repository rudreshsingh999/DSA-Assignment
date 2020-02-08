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
    int * ptr[n];
    int size[n];
    for(int x = 0; x < n; x++) {
    	ptr[x] = (int *)(calloc(1,sizeof(int)));
    	size[x] = 1;
    }

    for (int x = 0; x < n-1; x++) {
    	int a, b;
    	scanf("%d %d", &a, &b);
    	ptr[a][size[a]-1] = b;
    	ptr[b][size[b]-1] = a;

    	ptr[a] = realloc(ptr[a], size[a] + 1);
    	ptr[b] = realloc(ptr[b], size[b] + 1);
    	size[a]++;
    	size[b]++;
    }

    int stack[2*n];
    int level[n];
    for(int x = 0; x < n; x++) {
    	level[x] = -1;
    }
    int i = 0;
    int j = 0;
    stack[j] = 0;
    level[0] = 0;
    j++;
    int max1 = 0;
    while(i < j) {
    	int a = stack[i];
    	i++;
    	for(int x = 0; x < size[a]-1; x++) {
    		if(level[ptr[a][x]] == -1) {
    			level[ptr[a][x]] = level[a] + 1;
    			stack[j] = ptr[a][x];
    			j++;
    			if(level[a] + 1 > max1)
    				max1 = level[a] + 1;
    		}
    	}
    }

    int min_n1 = n;
    int max_n1 = 0;
    for(int x = 0; x < n; x++) {
    	if(level[x] == max1) {
    		if(x > max_n1)
    			max_n1 = x;
    		if(x < min_n1)
    			min_n1 = x;

    	}
    }

    printf("%d %d\n", max_n1, min_n1);

    for(int x = 0; x < n; x++) {
    	level[x] = -1;
    }
    i = 0;
    j = 0;
    stack[j] = min_n1;
    level[min_n1] = 0;
    j++;
    max1 = 0;
    while(i < j) {
    	int a = stack[i];
    	i++;
    	for(int x = 0; x < size[a]-1; x++) {
    		if(level[ptr[a][x]] == -1) {
    			level[ptr[a][x]] = level[a] + 1;
    			stack[j] = ptr[a][x];
    			j++;
    			if(level[a] + 1 > max1)
    				max1 = level[a] + 1;
    		}
    	}
    }

    // printf("%d\n", max1);
    int max_n2 = 0;
    int min_n2 = n;
    for(int x = 0; x < n; x++) {
    	if(level[x] == max1) {
    		if(x > max_n2)
    			max_n2 = x;
    		if(x < min_n2)
    			min_n2 = x;
    	}
    }

    int r = min_n2 < min_n1 ? min_n2 : min_n1;
    int s = max_n2 < max_n1 ? max_n1 : max_n2;

    printf("%d %d\n", r, s);
}