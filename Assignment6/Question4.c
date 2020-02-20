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
    int * stack;
    stack = (int *)(calloc(1, sizeof(int)));
    int i = -1;
    int minEle;
    for(int x = 0; x < n; x++) {
    	char s[10];
    	int a;
    	scanf("%s", s);

    	if(s[1] == 'u') {
    		scanf("%d", &a);
    		printf("OK pushed %d\n", a);
    		if(i == -1) {
    			minEle = a;
    		}
    		else {
    			if(a < minEle) {
    				// printf("Yes");
    				int t = minEle;
    				minEle = a;
    				a = 2*a - t;
    			}
    		}
    		stack[++i] = a;
    		
    		stack = realloc(stack, i+2); 
    	}
    	else if(s[1] == 'o') {
            if(i == -1)
                printf("STACK UNDERFLOW");
            else {
        		if(stack[i] < minEle) {
        			printf("OK poped %d\n", minEle);
        			minEle = 2*minEle - stack[i--];
        		}
        		else
        			printf("OK poped %d\n", stack[i--]);

        		stack = realloc(stack, i+2);
            }
    	}
    	else if(s[2] == 'e') {
    		printf("%d\n", stack[i]);
    	}
    	else {
    		printf("%d\n", minEle);
    	}
    }

}