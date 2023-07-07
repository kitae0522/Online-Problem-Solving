#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

using ll = long long;
unordered_map<ll, ll> M;
ll N, P, Q;

ll f(ll _n, ll _p, ll _q)
{
    if (_n == 0) return 1;
    if (M.find(_n) != M.end()) return M[_n]; // 최적화
    return M[_n] = f(_n / _p, _p, _q) + f(_n / _q, _p, _q);
}

int main()
{
    STDIO();
    cin >> N >> P >> Q;
    cout << f(N, P, Q) << '\n';
    return 0;
}