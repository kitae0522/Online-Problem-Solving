#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int N, R;
string S;

void f(int x)
{
	if (x == N) { R++; return; }
	f(x + 1);
	if (x + 7 < N && S.substr(x, 8) == "longlong") f(x + 8);
}

int main()
{
	STDIO();
	cin >> N >> S;
	f(0);
	cout << R << '\n';
}