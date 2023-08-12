#include <bits/stdc++.h>
using namespace std;

int i;
vector<int> V;

void f(int s, int e)
{
	if (s >= e) return;
	for (i = s + 1; i < e; ++i) if (V[s] < V[i]) break;
	f(s + 1, i);
	f(i, e);
	cout << V[s] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, idx = 0; while (cin >> n) V.push_back(n), idx++;
	f(0, idx);
}