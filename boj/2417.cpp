#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

using ull = unsigned long long;

int main()
{
    STDIO();
    ull N; cin >> N;
    ull L = 0, R = (1LL << 32) - 1;
    while (L < R)
    {
        ull M = (L + R) / 2;
        if (M * M >= N) R = M;
        else L = M + 1;
    }
    cout << L << '\n';
    return 0;
}