#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A, B, R = INT_MAX;

void f(ll N, int C)
{
	if (N > B) return;
	if (N == B) R = min(R, static_cast<ll>(C) - 1);
	f(N * 2, C + 1);
	f(N * 10 + 1, C + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> A >> B;
	f(A, 1);
	if (R == INT_MAX) cout << -1 << '\n';
	else cout << R + 1 << '\n';
	return 0;
}