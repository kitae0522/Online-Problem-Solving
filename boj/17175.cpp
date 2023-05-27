#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int MOD = 1e9 + 7;
int dp[1'010'101] = {0, 1,};
int n;

int main()
{
    STDIO();
    cin >> n;
    for(int i=2; i<=n; ++i)
    {
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= MOD;
    }
    cout << dp[n] << '\n';
    return 0;
}
