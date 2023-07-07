#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<int> graph[100001];
bool visited[100001];
int visited_v[100001];
int order;

void dfs(int node)
{
    if (visited[node]) return;
    visited[node] = true;
    visited_v[node] = ++order;
    for (int next_node: graph[node]) dfs(next_node);
}

int main()
{
    STDIO();
    int N, M, R;
    cin >> N >> M >> R;

    for (int i = 1; i <= M; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= N; ++i) sort(graph[i].begin(), graph[i].end());
    dfs(R);
    for (int i = 1; i <= N; ++i) cout << visited_v[i] << '\n';

    return 0;
}