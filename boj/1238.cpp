#include <bits/stdc++.h>
using namespace std;

constexpr int MX = 0x3f3f3f3f;

vector<pair<int, int>> edges[1010];

int dijkstra(int start_vertex, int end_vertex)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(1010, MX);

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
    return dist[end_vertex];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<int> R;
    int N, M, X;
    cin >> N >> M >> X;

    for (int i = 0; i < M; ++i)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges[from].push_back({weight, to});
    }

    for (int i = 1; i <= N; ++i) R.push(dijkstra(i, X) + dijkstra(X, i));
    cout << R.top() << '\n';
}

