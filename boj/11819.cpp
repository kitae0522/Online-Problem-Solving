#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

using ll = long long;

ll f(ll a, ll b, ll c)
{
    if (c == 1) return 0;
    ll result = 1;
    a %= c;
    while (b > 0)
    {
        if (b % 2 == 1) result = (result * a) % c;
        b = b >> 1;
        a = (a * a) % c;
    }
    return result;
}

int main()
{
    STDIO();
    ll A, B, C; cin >> A >> B >> C;
    cout << f(A, B, C) << '\n';
    return 0;
}
