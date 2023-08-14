#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string st; cin >> st;
    int ans = 0; for (auto c: st) ans += pow(c - '0', 5);
    cout << ans << '\n';
}
