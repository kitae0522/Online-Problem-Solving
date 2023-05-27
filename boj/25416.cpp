#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int r, c;

vector<vector<int>> m(5, vector<int>(5, 0));
vector<vector<bool>> v(5, vector<bool>(5, false));

int bfs(int x, int y)
{
    v[x][y] = true;

    queue<tuple<int, int, int>> q;
    q.emplace(x, y, 0);

    while (!q.empty())
    {
        int cx, cy, cc;
        tie(cx, cy, cc) = q.front();
        q.pop();

        if (m[cx][cy] == 1) return cc;

        for (int i = 0; i < 4; ++i)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 <= nx && nx < 5 && 0 <= ny && ny <= 5 && !v[nx][ny] && m[nx][ny] != -1)
            {
                v[nx][ny] = true;
                q.emplace(nx, ny, cc + 1);
            }
        }
    }
    return -1;
}

int main()
{
    STDIO();
    for (auto &i: m) for (int &j: i) cin >> j;
    cin >> r >> c;
    cout << bfs(r, c) << '\n';

    return 0;
}
