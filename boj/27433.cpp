#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll fact(int n)
{
	ll r = 1;
	for (ll i = 2; i <= n; ++i) r *= i;
	return r;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N; cin >> N;
	cout << fact(N) << '\n';
	return 0;
}
