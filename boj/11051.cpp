#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

constexpr int p = 10007;
using ll = long long;
ll n, m;

ll f()
{
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (j == 0 || i == j) dp[i][j] = 1;
            else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % p;
        }
    }
    return dp[n][m];
}

int main()
{
    STDIO();
    cin >> n >> m;
    cout << f() << '\n';
    return 0;
}