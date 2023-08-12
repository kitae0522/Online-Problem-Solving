#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, K; cin >> N >> K;
	vector<int> V;
	for (int i = 1; i <= N; ++i) if (!(N % i)) V.push_back(i);
	if (V.size() < K) cout << 0;
	else cout << V[K - 1];
	return 0;
}