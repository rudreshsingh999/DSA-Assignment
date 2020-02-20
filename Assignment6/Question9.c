#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    char stack[10][100000];
    int st[10];
    int k = -1;
    char str[1000];
    int i = -1;
    scanf("%s", str);
    int ans = 0;
    for(int x = 0; x < strlen(str); x++) {
    	if(str[x] >= 48 && str[x] <= 57) {
    		char r[2];
    		r[0] = str[x];
    		r[1] = '\0';
    		strcpy(stack[++i], r);
    		st[++k] = str[x]-48;
    	}
    	else {
    		char r1[100];
    		strcpy(r1, stack[i--]);
    		char r2[100];
    		strcpy(r2, stack[i--]);
    		int a = st[k--];
    		int b = st[k--];
    		int c;
    		if(str[x] == '+')
    			c = a + b;
    		else if(str[x] == '-')
    			c = b - a;
    		else if(str[x] == '*')
    			c = b*a;
    		else
    			c = b/a;
    		st[++k] = c;
    		// printf("%s %s", r1, r2);
    		char r3[100];
    		r3[0] = '(';
    		int j = 1;
    		for(int y = 0; y < strlen(r2); y++) {
    			r3[j] = r2[y];
    			j++;
    		}
    		r3[j++] = str[x];
    		for(int y = 0; y < strlen(r1); y++) {
    			r3[j++] = r1[y];
    		}

    		r3[j++] = ')';
    		r3[j] = '\0';
    		strcpy(stack[++i], r3);
    	}
    }
    printf("%d\n", st[k]);
    printf("%s", stack[i]);
}