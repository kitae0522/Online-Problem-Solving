#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

using ll = long long;

ll factorial(ll n, ll p)
{
    ll res = 1;
    for (ll i = 1; i <= n; ++i)
    {
        res *= i;
        res %= p;
    }
    return res;
}

int main()
{
    STDIO();
    ll N, P; cin >> N >> P;
    cout << factorial(N, P) << '\n';
    return 0;
}