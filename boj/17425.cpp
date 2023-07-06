#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

constexpr int MAX = 1'010'101;
using ll = long long;

ll dp[MAX];
int T, N;

int main()
{
    STDIO();
    cin >> T;
    for (int i = 1; i <= MAX; ++i) for (int j = i; j <= MAX; j += i) dp[j] += i;
    for (int i = 2; i <= MAX; ++i) dp[i] += dp[i - 1];
    for (int i = 1; i <= T; ++i)
    {
        cin >> N;
        cout << dp[N] << '\n';
    }
    return 0;
}