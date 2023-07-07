#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int dp[1010101];
int n;

int main()
{
    STDIO();
    cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    cout << dp[n] << '\n';
    return 0;
}
