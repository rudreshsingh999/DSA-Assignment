#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    char c[50];
    scanf("%s", c);
    char ans[50];
    int i = 0;
    ans[i] = c[0];
    int match = 0;
    for(int x = 1; x < strlen(c); x++) {
    	if(c[x] == ans[i])
    		match = 1;
    	else {
    		if(match == 0) {
    			i++;
    			ans[i] = c[x];
    		}
    		else {
    			i--;
    			x--;
    		}
    		match = 0;
    	}
    }
    if(match == 1) {
    	i--;
    }
   	if(i < 0) {
   		printf("VANISHED");
   	}
    for(int x = 0; x <= i; x++) {
    	printf("%c", ans[x]);
    }
}