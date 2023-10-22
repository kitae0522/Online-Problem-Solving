#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll summation(ll n)
{
    return n * (n + 1) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N; cin >> N;
    ll C, L = 1, R = N;
    while (L <= R)
    {
        ll M = (L + R) / 2;
        if (summation(M) > N)  R = M - 1;
        else C = M, L = M + 1;
    }
    cout << C;
    return 0;
}
