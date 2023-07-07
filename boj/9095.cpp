#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int dp[11] = {1, 2, 4};

int main()
{
    STDIO();
    // a(n-1) + a(n-2) + a(n-3) = a(n)
    for (int i = 3; i < 11; i++) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    int T; cin >> T;
    for (int i = 0, X; i < T; i++)
    {
        cin >> X;
        cout << dp[X - 1] << '\n';
    }
    return 0;
}