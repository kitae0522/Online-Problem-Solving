#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

constexpr int MAX = 101'010;

int main()
{
    STDIO();
    int N, arr[MAX], dp[MAX];
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    for(int i = 1; i < N; ++i) dp[i] = max(dp[i], dp[i - 1] + arr[i]);
    cout << *max_element(dp, dp + N) << '\n';

    return 0;
}