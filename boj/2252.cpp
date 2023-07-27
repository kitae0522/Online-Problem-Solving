#include <bits/stdc++.h>
using namespace std;

int N, M, I[32323];
vector<int> G[32323];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    queue<int> Q;
    cin >> N >> M;
    for (int i = 1, s, e; i <= M; ++i) cin >> s >> e, G[s].push_back(e), I[e]++;
    for (int i = 1; i <= N; ++i) if (!I[i]) Q.push(i);
    while (!Q.empty())
    {
        int v = Q.front(); Q.pop();
        cout << v << ' ';
        for (auto i: G[v]) if (!--I[i]) Q.push(i);
    }
    return 0;
}