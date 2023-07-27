#include <bits/stdc++.h>
using namespace std;

int N, M, P, Q;
vector<int> A;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M; A.resize(N + 1);
	for (int i = 1; i <= N; ++i) A[i] = i;
	for (int i = 1; i <= M; ++i)
	{
		cin >> P >> Q;
		for (int j = 0; j <= (Q-P) / 2; ++j) swap(A[j + P], A[Q - j]);
	}
	for (int i = 1; i <= N; ++i) cout << A[i] << ' ';
	return 0;
}