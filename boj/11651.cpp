#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;

int main()
{
    STDIO();
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &[x, y]: v) cin >> x >> y;
    sort(v.begin(), v.end(), [](auto i, auto j)
    {
        if (i.second == j.second) return i.first < j.first;
        return i.second < j.second;
    });
    for (auto &[x, y]: v) cout << x << " " << y << "\n";

    return 0;
}
