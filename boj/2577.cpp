#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> num_counter(10, 0);
	int a, b, c; cin >> a >> b >> c;
	string s = to_string(a * b * c);

	for (auto &c : s) num_counter[c - '0']++;
	for (auto &i : num_counter) cout << i << '\n';
}