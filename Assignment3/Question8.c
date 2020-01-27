#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void d_to_b(int n, char st[]) {
	char s[33];
	int t = n;
	int i = 0;
	while(t!=0) {
		int d = t%2;
		s[i] = (char)(48+d);
		i++;
		t/=2;
	}
	for(int x = i-1; x >= 0; x--) {
		st[i-1-x] = s[x];
	}
	st[i] = '\0';
}

int b_to_d(char s[]) {
	int len = strlen(s);
	len--;
	int r = 0;
	int i = 0;
	while(len>=0) {
		r = r + (s[i]-48)*pow(2,len);
		i++;
		len--;
	}

	return r;
}

int main() {
	
	int t;
	char c2;
	scanf("%d%c", &t, &c2);

	while(t--) {
		char c,c1;
		scanf("%c%c", &c, &c1);
		// printf("%c", c);
		if(c == 'G') {
			int n;
			scanf("%d%c", &n, &c2);
			char b[33];
			d_to_b(n, b);
			char r[33];
			r[0] = b[0];
			for (int x = 1; x < strlen(b); x++) {
				r[x] = (char)(48 + (b[x]-48)^(b[x-1]-48));
			}
			r[strlen(b)] = '\0';
			printf("%s\n", r);
		}
		else {
			char s[33];
			scanf("%s", s);
			char r[33];
			r[0] = s[0];
			for (int x = 1; x < strlen(s); x++) {
				r[x] = (char)(48 + (r[x-1]-48) ^ (s[x]-48));
			}
			r[strlen(s)] = '\0';
			int d = b_to_d(r);
			printf("%d\n", d);
		}
	}
}