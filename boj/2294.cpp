#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

constexpr int MAX = 1'010'101'010;
typedef vector<int> vi;

int main()
{
    STDIO();
    int N, K; cin >> N >> K;
    vi V(N); for (auto &item: V) cin >> item;
    vi dp(K + 1, MAX); dp[0] = 0;
    for (int &coin: V) for (int i = coin; i < K + 1; ++i) dp[i] = min(dp[i], dp[i - coin] + 1);
    cout << (dp[K] == MAX ? -1 : dp[K]) << '\n';
    return 0;
}