#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define M 998244353
#define ll long long int
 

ll modularExpo(ll x, ll y, ll p) {
	if(y == 0)
		return 1;
	else if (y % 2 == 0)
		return modularExpo((x*x) % p, y/2, p) % p;
	else
		return (x * modularExpo((x*x) % p, (y-1)/2, p)) % p;
}

ll modInverse(ll n, ll p) 
{ 
    return modularExpo(n, p-2, p); 
} 

ll nCrModPFermat(ll n, ll r, ll p) 
{ 
 
   if (r==0) 
      return 1; 

    ll fac[n+1]; 
    fac[0] = 1; 
    for (ll i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
  
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
} 



int main() {
	int x1, y1, z1;
	int x2, y2, z2;

	scanf("%d %d %d", &x1, &y1, &z1);
	scanf("%d %d %d", &x2, &y2, &z2);
	ll a = abs(x1 - x2);
	ll b = abs(y1 - y2);
	ll c = abs(z1 - z2);

	ll n = a + b + c;
	ll m = a + b;
	printf("%lld %lld %lld %lld %lld\n", a, b, c, n, m);  
	ll r = nCrModPFermat(n, c, M);
	ll s = nCrModPFermat(m, a, M);
	ll ans = (r%M * s%M)%M;
	printf("%lld\n", ans);
	return 0;
}