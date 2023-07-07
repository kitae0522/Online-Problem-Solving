#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int N, M, A, B, K, OBX, OBY, SX, SY, EX, EY;

int arr[505][505];
bool visited[505][505];
queue<pair<pair<int, int>, int>> q;

bool can_visit(int _y, int _x)
{
    if (_y < 0 || _x < 0 || _y + A > N || _x + B > M) return false;
    for (int i = _y; i < _y + A; ++i)
        for (int j = _x; j < _x + B; ++j)
            if (arr[i][j] == -1) return false;
    return true;
}

int bfs(int cy, int cx, int ty, int tx)
{
    q.push({{cy, cx}, 0});
    visited[cy][cx] = true;

    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int c = q.front().second;
        q.pop();

        if (x == tx && y == ty) return c;

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (can_visit(ny, nx) && !visited[ny][nx])
            {
                visited[ny][nx] = true;
                q.push({{ny, nx}, c + 1});
            }
        }
    }
    return -1;
}

int main()
{
    STDIO();
    cin >> N >> M >> A >> B >> K;
    for (int i = 1; i <= K; ++i)
    {
        cin >> OBX >> OBY;
        arr[OBX - 1][OBY - 1] = -1;
    }
    cin >> SY >> SX >> EY >> EX;
    int res = bfs(--SY, --SX, --EY, --EX);
    cout << res << '\n';

    return 0;
}
