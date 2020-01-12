#include <stdio.h>
#include <math.h>
int main() {
	long long int a,b;
	scanf("%lld %lld", &a, &b);
	int n = 1000000;
	int ar[n+1];

	for (long long int x = 0; x <= n; x++) {
		ar[x] = 0;
	}

	for (long long int x = 2; x*x <= n; x++) {
		if (ar[x] == 0) {
			for (int y = 2*x; y <= n; y+=x) {
				ar[y] = 1;
			}	
		}
	}
	long long int c = 0;
	for (long long int x=2;x<=n;x++) {
		if (ar[x] == 0) 
			c++;
	}

	int primes[c];
	int i = 0;
	for (long long int x=2;x<=n;x++) {
		if (ar[x] == 0) {
			primes[i] = x;
			i++;
		}
	}

	int range[b-a+1];
	for (long long int x = 0; x <= b-a; x++) {
		range[x] = 0;
	}

	// printf("%d\n",primes[0]);
	for (long long int x = 0; x < c; x++) {

		if(primes[x]*primes[x] > b)
			break;


		long long int r = floor(a/primes[x])*primes[x];
		if (r < a) {
			r += primes[x];
		}

		if (r == primes[x]) 
			r += primes[x];

		for (long long int y = r; y <= b; y+=primes[x]) {
			range[y-a] = 1;
		}
	}

	// for (int x = 0; x <= b-a; x++) {
	// 	printf("%d ", range[x]);
	// }

	c = 0;
	for (long long int x=0; x <= b-a; x++) {
		if (range[x] == 0) {
			c++;
		}
	}
	long long int ans[c];
	i = 0;
	for (long long int x=0; x <= b-a; x++) {
		if (range[x] == 0) {
			ans[i] = x+a;
			i++;
		}
	}

	long long int digits[10];
	for (int x=0; x<10; x++) {
		digits[x] = 0;
	}

	for (long long int x = 0; x < c; x++) {
		long long int t = ans[x];
		while(t!=0) {
			int d = t%10;
			digits[d]++;
			t/=10;

		}
	}
	i = 0;
	for (long long int x=1;x<10;x++) {
		if(digits[x] > digits[i]) {
			i = x;
		}
	}

	printf("%d %lld",i,digits[i]);
	printf("\n");
	return 0;
}