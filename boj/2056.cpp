#include <bits/stdc++.h>

using namespace std;

int N, M, R, I[10101], D[10101], A[10101];
vector<int> G[10101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    queue<int> Q;
    cin >> N;
    for (int i = 1, k, x; i <= N; ++i)
    {
        cin >> k >> x, A[i] = k;
        for (int j = 1, v; j <= x; ++j) cin >> v, G[v].push_back(i), I[i]++;
    }
    for (int i = 1; i <= N; ++i) if (!I[i]) Q.push(i), D[i] = A[i];
    while (!Q.empty())
    {
        int v = Q.front(); Q.pop();
        for (auto i: G[v])
        {
            D[i] = max(D[i], D[v] + A[i]);
            if (!--I[i]) Q.push(i);
        }
    }
    for (int i = 1; i <= N; ++i) R = max(R, D[i]);
    cout << R << '\n';
    return 0;
}