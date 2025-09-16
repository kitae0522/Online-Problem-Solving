#include <bits/stdc++.h>
using namespace std;

constexpr int MX = 0x3f3f3f3f;

vector<pair<int, int>> edges[20202];
vector<int> dist(20202, MX);

void dijkstra(int start_vertex)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start_vertex] = 0;
    pq.push({dist[start_vertex], start_vertex});

    while (!pq.empty())
    {
        int weight = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();

        if (weight > dist[vertex]) continue;
        for (auto nxt : edges[vertex])
        {
            int nxt_weight = nxt.first;
            int nxt_vertex = nxt.second;
            if (dist[nxt_vertex] > weight + nxt_weight)
            {
                dist[nxt_vertex] = weight + nxt_weight;
                pq.push({dist[nxt_vertex], nxt_vertex});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int V, E, K;
    cin >> V >> E >> K;
    for (int i = 0; i < E; ++i)
    {
        int from_vertex, to_vertex, weight;
        cin >> from_vertex >> to_vertex >> weight;
        edges[from_vertex].push_back({weight, to_vertex});
    }

    dijkstra(K);
    for (int i = 1; i <= V; ++i)
    {
        if (dist[i] == MX) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}

