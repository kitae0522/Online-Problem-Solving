#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string S;

int main()
{
	STDIO();
	cin >> S;
	sort(S.begin(), S.end());
	if (!binary_search(S.begin(), S.end(), 'M')) cout << "NO";
	else if (!binary_search(S.begin(), S.end(), 'O')) cout << "NO";
	else if (!binary_search(S.begin(), S.end(), 'B')) cout << "NO";
	else if (!binary_search(S.begin(), S.end(), 'I')) cout << "NO";
	else if (!binary_search(S.begin(), S.end(), 'S')) cout << "NO";
	else cout << "YES";
	return 0;
}