#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

using ll = long long;

int f(int a, int b, int c)
{
    if (b == 0) return 1;
    ll tmp = f(a, b / 2, c);
    ll res = (tmp * tmp) % c;
    if (b % 2 == 1) res = (res * a) % c;
    return static_cast<int>(res);
}

int main()
{
    STDIO();
    int a, b, c; cin >> a >> b >> c;
    cout << f(a, b, c) << '\n';
    return 0;
}