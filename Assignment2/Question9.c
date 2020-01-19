#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int ar1[10];
	int ar2[10];
	for (int x = 0; x < 10; x++) {
		ar1[x] = 0;
		ar2[x] = 0;
	}
	int count = 0;
	while(1) {
		char ch;
		scanf("%c", &ch);
		if( ch == '\n')
			break;
		ar1[ch - 48]++;
		ar2[ch - 48]++;
		count++;
	}
	// printf("%d",ar[1]);
	int i = 0;
	int f = 0;
	if(ar2[0] != 0) {
		for (int x = 1; x < 10; x++) {
			if( ar2[x] != 0)
				i = x;
				break;
		}
		ar2[i]--;
		f = 1;
	}
	// printf("%d\n", ar1[1]);
	int r = 9;
	int s = 0;
	int carry = 0;
	char str[100000];
	int itr = 0;
	int ans = 0;
	while(count--) {
		while (r>=0 && ar2[r] == 0)
			r--;
		while (s<=9 && ar1[s] == 0)
			s++;

		if(r<0)
			break;
		ans = s - r + carry;
		printf("%d %d %d \n", ans, r, s);
		ar1[s]--;
		ar2[r]--;
		if (ans < 0) {
			printf("%c\n", (char)(10 + ans + 48));
			str[itr++] = (char)(10 + ans + 48);
			carry = -1;
		}
		else {
			printf("%c\n", (char)(ans + 48));
			str[itr++] = (char)(ans + 48);
			carry = 0;
		}
	}
	if(f == 1) {
		printf("%d %d %d \n", s - i, i, s);
		str[itr++] = (char)(s - i + 48);
		printf("%c\n", (char)(s - i + 48));
	}

	printf("%d\n", itr);
	for (int x = itr-1; x >= 0; x--) {
		printf("%c",str[x]);
	}
}