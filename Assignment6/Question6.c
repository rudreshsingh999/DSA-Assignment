#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    char s[100];
    scanf("%s", s);

    char stack[100];
    int i = -1;

    for(int x = 0; x < strlen(s); x++) {
    	if(s[x] == '[' || s[x] == '(' || s[x] == '{') {
    		stack[++i] = s[x];
    	}
    	else {
    		if(s[x] == ')' && stack[i] == '(') {

    		}
    		else if(s[x] == '}' && stack[i] == '{') {

    		}
    		else if(s[x] == ']' && stack[i] == '[') {

    		}
    		else {
    			printf("NO");
    			return 0;
    		}
    		i--;
    	}
    }
    printf("YES");
}