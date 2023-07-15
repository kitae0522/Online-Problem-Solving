#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

using ll = long long;
ll dp[91];

ll fibo(int n)
{
    if (n == 0 || n == 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
    STDIO();
    for (ll & i : dp) i = -1;
    int N; cin >> N;
    cout << fibo(N) << '\n';
    return 0;
}