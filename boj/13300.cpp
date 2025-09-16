#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k, c = 0; cin >> n >> k;
	int r[2][7] = {};

	for (int i=0; i<n; ++i) {
		int s, g; cin >> s >> g;
		r[s][g]++;
	}

	for (int s=0; s<2; ++s) {
		for (int g=1; g<=6; ++g) {
			c += (r[s][g] + k - 1) / k;
		}
	}

	cout << c << '\n';
}