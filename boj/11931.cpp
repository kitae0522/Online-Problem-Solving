#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main()
{
    STDIO();
    int N; cin >> N; vector<int> v(N);
    for (auto &i: v) cin >> i;
    sort(v.begin(), v.end(), [](auto x, auto y){ return x > y; });
    for (auto &i: v) cout << i << '\n';
    return 0;
}