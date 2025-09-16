#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MX = 0x3f3f3f3f;
vector<pair<ll, ll>> edges[808];

int N, M, V1, V2;

ll dijkstra(int start_vertex, int end_vertex)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    vector<ll> dist(808, MX);

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
            }
        }
    }

    return dist[end_vertex];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges[from].push_back({weight, to});
        edges[to].push_back({weight, from});
    }
    cin >> V1 >> V2;

    // < First Case >
    // 1st weight: 1 -> V1
    // 2nd weight: V1 -> V2
    // 3rd weight: V2 -> N
    ll fr = dijkstra(1, V1) + dijkstra(V1, V2) + dijkstra(V2, N);

    // < Second Case>
    // 1st weight: 1 -> V2
    // 2rd weight: V2 -> V1
    // 3nd weight: V1 -> N
    ll sr = dijkstra(1, V2) + dijkstra(V2, V1) + dijkstra(V1, N);

    ll answer = min(fr, sr);
    cout << (answer >= MX ? -1 : answer) << '\n';

    // btw, i think floyd-warshall is a better way to implement this problem...
    // absolutely, using dijkstra 3 times is faster than floyd-warshall :-)
}

