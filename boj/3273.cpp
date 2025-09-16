#include <bits/stdc++.h>
using namespace std;

int fn(vector<int> v, int x, int mx)
{
    vector<int> nums(mx + 1, 0);
    int r = 0;

    for (auto i : v)
    {
        int required_num = x - i;
        if (required_num < 0 || required_num > mx) continue;
        if (nums[required_num]) r++;
        nums[i]++;
    }

    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> v;
    int n, x;

    cin >> n;
    for (int i = 0, a; i < n; ++i) cin >> a, v.push_back(a);
    cin >> x;

    cout << fn(v, x, *max_element(v.begin(), v.end())) << '\n';
}
