#include <bits/stdc++.h>
using namespace std;

constexpr int mn = 1e9;
int maps[10][10];
bool visited[10][10];
int n, m;

queue<pair<int, int>> Q;
vector<pair<int, int>> S;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs()
{
    queue<pair<int, int>> TQ = Q;
    int R = 0;

    while (!TQ.empty())
    {
        pair<int, int> curr = TQ.front();
        TQ.pop();

        visited[curr.first][curr.second] = true;
        for (int i = 0; i < 4; ++i)
        {
            int nx = dx[i] + curr.first;
            int ny = dy[i] + curr.second;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (maps[nx][ny] != 0 || visited[nx][ny]) continue;

            visited[nx][ny] = true;
            TQ.push({nx, ny});
            R++;
        }
    }
    return R;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int answer = mn, safety = 0;

    // initialize
    for (int i = 0; i < 10; ++i) fill(maps[i], maps[i] + 10, -1);

    // input maps
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> maps[i][j];
            if (maps[i][j] == 0) S.push_back({i, j}), safety++;
            if (maps[i][j] == 2) Q.push({i, j});
        }

    for (int i = 0; i < S.size() - 2; ++i)
        for (int j = i + 1; j < S.size() - 1; ++j)
            for (int k = j + 1; k < S.size(); ++k)
            {
                for (int o = 0; o < 10; ++o) fill(visited[o], visited[o] + 10, false);
                maps[S[i].first][S[i].second] = maps[S[j].first][S[j].second] = maps[S[k].first][S[k].second] = 1;
                answer = min(answer, bfs());
                maps[S[i].first][S[i].second] = maps[S[j].first][S[j].second] = maps[S[k].first][S[k].second] = 0;
            }
    cout << safety - answer - 3;
}

