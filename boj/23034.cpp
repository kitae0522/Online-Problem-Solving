#include <bits/stdc++.h>
using namespace std;

constexpr int MXN = 1e3 + 5;
constexpr int MXM = 1e5 + 5;

using pii = pair<int, int>;

struct edge
{
    int u, v, c;

    bool operator<(const edge &a) const
    {
        return c < a.c;
    }
};

vector<pii> adj[MXN];
int N, M, Q, R;
int P[MXN], dist[MXN][MXN];

int find_root(int x)
{
    return P[x] < 0 ? x : P[x] = find_root(P[x]);
}

void bfs(int x)
{
    vector<bool> V(MXN, false);
    V[x] = true;
    queue<int> q;
    q.push(x);
    while (!q.empty())
    {
        int h = q.front();
        q.pop();
        for (auto [tx, cost]: adj[h])
        {
            if (!V[tx])
            {
                dist[x][tx] = max({dist[x][tx], dist[x][h], cost});
                V[tx] = true;
                q.push(tx);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fill_n(P, MXN, -1);
    cin >> N >> M;
    vector<edge> arr(M);
    for (auto &item: arr) cin >> item.u >> item.v >> item.c;
    sort(arr.begin(), arr.end());

    for (auto &[u, v, c]: arr)
    {
        int pu = find_root(u);
        int pv = find_root(v);
        if (pu != pv)
        {
            R += c;
            P[pu] = pv;
            adj[u].emplace_back(v, c);
            adj[v].emplace_back(u, c);
        }
    }
    for (int i = 1; i <= N; i++) bfs(i);

    cin >> Q;
    while (Q--)
    {
        int u, v;
        cin >> u >> v;
        cout << R - dist[u][v] << '\n';
    }
    return 0;
}

