#include <bits/stdc++.h>

using namespace std;

int N, M, I[1010], D[1010];
vector<int> G[1010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    queue<int> Q;
    cin >> N >> M;
    for (int i = 1, s, e; i <= M; ++i) cin >> s >> e, G[s].push_back(e), I[e]++;
    for (int i = 1; i <= N; ++i) if (!I[i]) Q.push(i), D[i] = 1;
    while (!Q.empty())
    {
        int v = Q.front(); Q.pop();
        for (auto i: G[v])
        {
            D[i] = max(D[i], D[v] + 1);
            if (!--I[i]) Q.push(i);
        }
    }
    for (int i = 1; i <= N; ++i) cout << D[i] << ' ';
    return 0;
}