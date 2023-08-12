#include <bits/stdc++.h>
using namespace std;

int T;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while (T--)
	{
		int N; double R = 0; cin >> N;
		for (int i = 1; i <= N; ++i) R += log10(i);
		cout << static_cast<int>(R + 1) << '\n';
	}
	return 0;
}