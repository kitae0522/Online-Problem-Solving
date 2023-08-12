#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 987654321;

int f(int x, int y, vector<string>& V)
{
	int cnt1 = 0, cnt2 = 0;
	char color[2] = {'B', 'W'};
	for (int i = x; i < x + 8; ++i)
	{
		for (int j = y; j < y + 8; ++j)
		{
			if (V[i][j] != color[(i + j) % 2]) cnt1++;
			if (V[i][j] != color[1 - (i + j) % 2]) cnt2++;
		}
	}
	return min(cnt1, cnt2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M, R = INF; cin >> N >> M;
	vector<string> V(N); for (auto &i: V) cin >> i;
	for (int i = 0; i + 8 <= N; ++i) for (int j = 0; j + 8 <= M; ++j) R = min(R, f(i, j, V));
	cout << R << '\n';
	return 0;
}