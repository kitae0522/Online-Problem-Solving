#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

tuple<int, int, string> t[3];

int main()
{
    STDIO();
    for (auto &[p, y, s]: t) cin >> p >> y >> s;
    sort(t, t + 3, [](auto x, auto y)
    { return get<1>(x) < get<1>(y); });
    for (auto & i : t) cout << get<1>(i) % 100;
    cout << "\n";
    sort(t, t + 3, [](auto x, auto y)
    { return get<0>(x) > get<0>(y); });
    for (auto & i : t) cout << get<2>(i)[0];
    return 0;
}
