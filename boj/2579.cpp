#include <bits/stdc++.h>
using namespace std;

int dp[303][3], s[303];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) cin >> s[i];

    dp[1][1] = s[1], dp[1][2] = 0, dp[2][1] = s[2], dp[2][2] = s[1] + s[2];
    for (int i = 3; i <= t; ++i)
    {
        dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + s[i];
        dp[i][2] = dp[i - 1][1] + s[i];
    }
    cout << max(dp[t][1], dp[t][2]) << '\n';
}
