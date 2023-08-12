#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	double A, B, C; cin >> A >> B >> C;
	double R = max(A * B / C, A / B * C);
	cout << static_cast<int>(R) << '\n';
	return 0;
}