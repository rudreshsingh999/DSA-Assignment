#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long int
#define M 1000000000
int main() {
	int q;
	scanf("%d", &q);
	for(int x = 0; x < q; x++) {
		ll n;
		scanf("%lld", &n);
		ll low = 0;
		ll high = M;
		while(low <= high) {
			ll mid = (low + high)/2;
			if(mid*mid > n) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}

		printf("%lld\n", low-1);
	}
}