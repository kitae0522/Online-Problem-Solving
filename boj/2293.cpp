#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

typedef vector<int> vi;

int main()
{
    STDIO();
    int N, K; cin >> N >> K;
    vi V(N); for (auto &item: V) cin >> item;
    vi dp(K + 1, 0); dp[0] = 1;
    for (int &coin: V) for (int i = coin; i < K + 1; ++i) dp[i] += dp[i - coin];
    cout << dp[K] << '\n';
    return 0;
}