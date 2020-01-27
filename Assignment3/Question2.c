#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long long int ar[5*1000000];
long long int func(long long int n) {
	if(n >= 5000000) {
		if(n % 2 == 0)
			return 1 + func(n/2);
		else
			return 1 + func(3*n + 1);
	}

	if (ar[n] == -1) {
		if(n % 2 == 0) {
			ar[n] = 1 + func(n/2);
		}
		else {
			ar[n] = 1 + func(3*n + 1);
		}
	}
	return ar[n];
}

int main() {
	int n;
	scanf("%d", &n);
	for (int x = 0; x < 5000000; x++) 
		ar[x] = -1;

	ar[0] = ar[1] = 0;
	ar[2] = 1;
	long long int  i = 0;
	long long int max = 0;
	for (long long int x = 3; x <= n; x++) {
		long long int r = func(x);
		if (r >= max) {
			max = r;
			i = x;
		}
	}


	printf("%lld %lld\n", i, max+1);
}