#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
int N, M;
priority_queue<pll, vector<pll>, greater<>> pq;

int main()
{
    STDIO();
    cin >> N >> M;
    for (int i = 1, t; i <= N; ++i)
    {
        cin >> t;
        pq.emplace(t, t);
    }
    for (int i = 1; i < M; ++i)
    {
        ll f, s;
        tie(f, s) = pq.top();
        pq.pop();
        pq.emplace(f + s, s);
    }
    cout << pq.top().first << '\n';
    return 0;
}