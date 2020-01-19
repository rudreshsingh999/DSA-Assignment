#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
	long long int n;
	scanf("%lld", &n);
	long long int t = n;
	long long int ans = 0;
	for (long long int x = 2; x <= sqrt(t); x++) {
		int f = 0;
		while (t % x == 0) {
			t = t/x;
			f = 1;
		}
		if (f == 1)
			ans = ans ^ x;
	}
	if (t != 1) {
		ans = ans ^ t;
	}

	printf("%lld\n", ans);
}