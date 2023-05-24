#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int MAX_SIZE = 101;

int arr[MAX_SIZE][MAX_SIZE];
int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int bfs()
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> cnt(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    visited[0][0] = true;
    cnt[0][0] = 1;
    q.push({0, 0});

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = dx[i] + cx;
            int ny = dy[i] + cy;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && arr[nx][ny] == 1)
            {
                cnt[nx][ny] = cnt[cx][cy] + 1;
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    return cnt[n - 1][m - 1];
}

int main()
{
    STDIO();
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        string st;
        cin >> st;
        for (int j = 0; j < m; ++j)
        {
            arr[i][j] = st[j] - '0';
        }
    }
    cout << bfs() << '\n';
    return 0;
}
