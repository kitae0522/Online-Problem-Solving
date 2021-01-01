#include <stdio.h>
#include <math.h>
#define ll long long
#define p 1000000007

ll fact(int x)
{
	ll n = 1;
	for (; x > 0; x--)
		n *= x;
	return n;
}

int main()
{
	
	ll N, K;
	scanf("%lld %lld", &N, &K);
	printf("%lld", (fact(N) % p) * (pow(fact(N - K) * fact(K), p - 2)) % p);
	
	return 0;
}
