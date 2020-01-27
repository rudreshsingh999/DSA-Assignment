#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
	char s[1001];
	char w[1001];

	scanf("%s", s);
	scanf("%s", w);
	int count = 0;
	for (int x = 0; x <= strlen(s)-strlen(w); x++) {
		int c = 0;
		for (int y = 0; y < strlen(w); y++) {
			if (s[x+y] != w[y]) 
				c++;
		}
		if(c <= 1) 
			count++;
	}
	printf("%d\n", count);
}