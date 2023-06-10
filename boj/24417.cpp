#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

typedef unsigned long long ull;

ull dp[2];

void fibo(int n)
{
    dp[0] = dp[1] = 1;
    for (int i = 2; i < n; ++i)
    {
        ull tmp = dp[0] + dp[1];
        if (tmp > 1000000006) tmp -= 1000000007;
        dp[0] = dp[1]; dp[1] = tmp;
    }
}

int main()
{
    STDIO();
    int t; cin >> t;
    fibo(t);
    cout << dp[1] << ' ' << t - 2 << '\n';
    return 0;
}