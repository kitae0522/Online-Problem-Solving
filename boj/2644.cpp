#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int bfs(vector<vector<int>> &graph, int start, int target)
{
    vector<int> visited(graph.size(), 0);
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == target)
            return visited[curr] - 1;

        for (int next: graph[curr])
        {
            if (!visited[next])
            {
                q.push(next);
                visited[next] = visited[curr] + 1;
            }
        }
    }

    return -1;
}

int main()
{
    STDIO();
    int n, person1, person2, m;
    cin >> n >> person1 >> person2 >> m;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int result = bfs(graph, person1, person2);
    cout << result << '\n';

    return 0;
}