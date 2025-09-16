#include <bits/stdc++.h>
using namespace std;

constexpr int MX = 0x3f3f3f3f;
// 최대 N + N의 사이즈가 들어올 수 있기 때문에 4000 * 2한만큼의 사이즈를 잡아줌.
vector<pair<int, int>> edges_fox[8080], edges_wolf[8080];
vector<int> dist_fox(8080, MX), dist_wolf(8080, MX);

int N, M, R;

vector<int> dijkstra(vector<pair<int, int>> edges[8080], vector<int>& dist)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[1] = 0;
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

    return dist;
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

        // 무방향 그래프이기 때문에, 두가지 케이스를 만들어줘야함
        // 또한 1/2 하면 실수처리를 해야하므로, 역으로 가중치를 2배 계산하여 추가해줌.
        edges_fox[from].push_back({weight * 2, to});
        edges_fox[to].push_back({weight * 2, from});

        // 홀수번째 이동에서는 기본 가중치(여우는 2배 곱했기 때문에, 자연스럽게 1/2한 효과를 얻을 수 있음)
        // 짝수번째 이동에서는 4배 곱한 가중치
        // 마찬가지로 무방향 그래프라 두가지 케이스 만들기
        edges_wolf[from].push_back({weight, to + N});
        edges_wolf[to].push_back({weight, from + N});
        edges_wolf[from + N].push_back({weight * 4, to});
        edges_wolf[to + N].push_back({weight * 4, from});
    }

    dijkstra(edges_fox, dist_fox);
    dijkstra(edges_wolf, dist_wolf);

    for (int i = 1; i <= N; ++i) R += dist_fox[i] < min(dist_wolf[i], dist_wolf[i + N]);
    cout << R << '\n';
}

