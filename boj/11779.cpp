#include <bits/stdc++.h>
using namespace std;

constexpr int MX = 0x3f3f3f3f;
vector<pair<int, int>> edges[1010];
vector<int> dist(1010, MX), pre(1010, 0);

void dijkstra(int start_vertex)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start_vertex] = 0;
    pq.push({dist[start_vertex], start_vertex});

    while (!pq.empty())
    {
        auto [weight, vertex] = pq.top();
        pq.pop();

        if (weight > dist[vertex]) continue;
        for (auto [nxt_weight, nxt_vertex] : edges[vertex])
        {
            if (dist[nxt_vertex] > weight + nxt_weight)
            {
                dist[nxt_vertex] = weight + nxt_weight;
                pq.push({dist[nxt_vertex], nxt_vertex});
                pre[nxt_vertex] = vertex;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, F, T;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges[from].push_back({weight, to});
    }
    cin >> F >> T;

    dijkstra(F);

    vector<int> path;
    for (int i = T; i; i = pre[i]) path.push_back(i);
    reverse(path.begin(), path.end());

    cout << dist[T] << '\n' << path.size() << '\n';
    for (auto i : path) cout << i << ' ';
}

