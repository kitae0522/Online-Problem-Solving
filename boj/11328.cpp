#include <bits/stdc++.h>
using namespace std;

string fn(string victim, string target) {
	if (victim.size() != target.size()) return "Impossible";

	int alpha_count[26] = {};
	for (auto &cv: victim) alpha_count[cv - 'a']++;
	for (auto &tv: target) alpha_count[tv - 'a']--;

	for (int i=0; i<26; ++i) {
		if (alpha_count[i] > 0 || alpha_count[i] < 0) return "Impossible";
	}

	return "Possible";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	for (int i=0; i<n; ++i) {
		string vs, ts; cin >> vs >> ts;
		cout << fn(vs, ts) << '\n';
	}
}