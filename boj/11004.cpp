#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, K; cin >> N >> K;
	vector<int> V(N); for (auto &i : V) cin >> i; sort(V.begin(), V.end());
	cout << V[K - 1];
	return 0;
}