#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	int ar[10];
	for (int x = 0; x < 10; x++) {
		ar[x] = 0;
	}

	for(int x = 0; x < n; x++) {
		int a;
		scanf("%d", &a);
		ar[a]++;
	}

	if(ar[0] == 0)
		printf("NO NUMBER");
	else {
		int s1 = ar[1] + ar[4] + ar[7];
		int s2 = ar[2] + ar[5] + ar[8];
		int r = s1 < s2 ? s1 : s2;
		int r1 = r;
		for (int x = 9; x >= 0; x--) {
			if(x % 3 == 0) {
				for (int y = 0; y < ar[x]; y++) {
					printf("%d", x);
				}
			}
			else if(x % 3 == 2) {
				for (int y = 0; y < ar[x]; y++) {
					if(r1 == 0)
						break;
					printf("%d", x);
					r1--;
				}
			}
			else {
				for (int y = 0; y < ar[x]; y++) {
					if(r == 0)
						break;
					printf("%d", x);
					r--;
				}
			}
		}
	}
}