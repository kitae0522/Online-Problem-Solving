#include <bits/stdc++.h>
using namespace std;

int fn(string s) {
	vector<int> nums(10, 0);
	int count = 0;

	for (auto &c : s) nums[c - '0']++;
	
	nums[6] = (nums[6] + nums[9] + 1) / 2;
	nums[9] = 0;

	return *max_element(nums.begin(), nums.end());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	cout << fn(to_string(n)) << '\n';
}