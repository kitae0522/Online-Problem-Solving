#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

using ll = long long;

template<typename T>
using V = vector<T>;

int M;
V<ll> dp;
char R;

char f(int _idx, ll _m)
{
    if (_idx <= 1) return "Messi Gimossi"[_m - 1];
    if (_m > dp[_idx - 1] + 1) return f(_idx - 2, _m - dp[_idx - 1] - 1);
    else if (_m < dp[_idx - 1]) return f(_idx - 1, _m);
    else return ' ';
}

int main()
{
    STDIO();
    cin >> M;
    dp.push_back(5); dp.push_back(13);
    while (dp[dp.size() - 1] < M) dp.push_back(dp[dp.size() - 1] + dp[dp.size() - 2] + 1);
    R = f((int) dp.size() - 1, M);
    if (R == ' ') cout << "Messi Messi Gimossi\n";
    else cout << R << '\n';
    return 0;
}