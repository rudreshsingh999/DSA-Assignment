#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char s[501];
	scanf("%s", s);
	int l = strlen(s);

	// even

	int low = 0;
	int high = l/2;
	int mark = -1;
	while(low <= high) {
		int mid = (low+high)/2;
		int t = 2*mid;
		int f = 0;
		for (int x = 0; x <= l-t; x++) {
			f = 0;
			for (int y = 0; y < t/2; y++) {
				if (s[x+y] != s[x+t-y-1]) {
					f = 1;
					break;
				}
			}
			if(f == 0) {
				mark = x;
				break;
			}
		}

		if(f == 0) {
			low = mid + 1;
			printf("%d\n", mid);
		}
		else {
			high = mid - 1;
		}
	} 
	
	int st1 = 2*(low-1);
	int mk1 = mark; 
	// odd

	low = 0;
	high = (l-1)/2;
	mark = -1;
	while(low <= high) {
		int mid = (low+high)/2;
		int t = 2*mid + 1;
		int f = 0;
		for (int x = 0; x <= l-t; x++) {
			f = 0;
			for (int y = 0; y < t/2; y++) {
				if (s[x+y] != s[x+t-y-1]) {
					f = 1;
					break;
				}
			}
			if(f == 0) {
				mark = x;
				break;
			}
		}

		if(f == 0) {
			low = mid + 1;
			printf("%d\n", mid);
		}
		else {
			high = mid - 1;
		}
	} 
	if(st1 > 2*low - 1) 
		printf("%d %d\n",2*(low-1),mark);
	else
		printf("%d %d\n",2*low-1,mark);
}