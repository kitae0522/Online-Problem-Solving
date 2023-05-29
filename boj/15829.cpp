#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

typedef unsigned long long ull;

constexpr int r = 31;
constexpr int m = 1234567891;

int main()
{
    int n;
    ull c = 1, hash = 0;
    string st;

    STDIO();
    cin >> n >> st;
    for (int i = 0; i < n; ++i)
    {
        hash += (st[i] - 'a' + 1) * c % m;
        hash %= m;
        c = (c * r) % m;
    }
    cout << hash << '\n';
    return 0;
}
