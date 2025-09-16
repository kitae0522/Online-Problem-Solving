#include <bits/stdc++.h>
using namespace std;

int maps[1010][1010];
int dist[1010][1010];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    queue<pair<int, int>> Q;
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> maps[i][j];
            if (maps[i][j] == 1) Q.push({i, j});
            if (maps[i][j] == 0) dist[i][j] = -1;
        }
    }

    while (!Q.empty())
    {
        pair<int, int> curr = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = dx[i] + curr.first;
            int ny = dy[i] + curr.second;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] >= 0) continue;

            Q.push({nx, ny});
            dist[nx][ny] = dist[curr.first][curr.second] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (dist[i][j] == -1)
            {
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans << '\n';
}
