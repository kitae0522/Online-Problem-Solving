#include <bits/stdc++.h>
using namespace std;

constexpr int MX = 0x3f3f3f3f;
vector<pair<int, int>> edges[125 * 125 + 1];
int maps[125 + 1][125 + 1];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dijkstra(int end_vertex)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(125 * 125 + 1, MX);

    dist[1] = maps[0][0];
    pq.push({dist[1], 1});

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

    for (int idx = 1; ; ++idx)
    {
        int N;
        cin >> N;
        if (!N) break;

        // input
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) cin >> maps[i][j];

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                for (int k = 0; k < 4; ++k)
                {
                    int nx = dx[k] + j;
                    int ny = dy[k] + i;

                    if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    edges[(N * i) + j + 1].push_back({maps[ny][nx], (N * ny) + nx + 1});
                }
            }
        }

        // output
        cout << "Problem " << idx << ": " << dijkstra(N * N) << '\n';

        // flush
        for (auto& edge : edges) edge.clear();
    }
}

