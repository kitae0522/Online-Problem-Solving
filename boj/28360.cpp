#include <bits/stdc++.h>

using namespace std;

int N, M, I[55];
double D[55];
vector<int> G[55];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    queue<int> Q;
    cin >> N >> M;
    D[1] = 100;
    for (int i = 1, s, e; i <= M; ++i) cin >> s >> e, G[s].push_back(e), I[e]++;
    for (int i = 1; i <= N; ++i) if (!I[i]) Q.push(i);
    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        for (auto i: G[v])
        {
            D[i] += D[v] / G[v].size();
            if (!--I[i]) Q.push(i);
        }
        if (!G[v].empty()) D[v] = 0;
    }
    cout << fixed << setprecision(15) << *max_element(D + 1, D + N + 1);
    return 0;
}