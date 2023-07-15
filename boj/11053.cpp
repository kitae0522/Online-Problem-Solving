#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, V[1010], dp[1010];

int f()
{
    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 1; --j) if (V[i] > V[j]) dp[i] = max(dp[i], dp[j] + 1);
        ans = max(dp[i], ans);
    }
    return ans;
}

int main()
{
    STDIO();
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> V[i];
    cout << f() << '\n';
    return 0;
}