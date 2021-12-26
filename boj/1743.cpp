#include <bits/stdc++.h>
using namespace std;

int X, Y, K, cnt = 1;
vector<int> V;

int arr[101][101];
bool visited[101][101];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx <= X && ny >= 0 && ny <= Y)
        {
            if (!visited[nx][ny] && arr[nx][ny] == 1) {
                visited[nx][ny] = true;
                cnt++;
                dfs(nx, ny);
            }
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> X >> Y >> K;

    while (K--)
    {
        int r, c;
        cin >> r >> c;
        arr[r][c] = 1;
    }

    for (int i = 1; i <= X; ++i)
    {
        for (int j = 1; j <= Y; ++j)
        {
            if (!visited[i][j] && arr[i][j] == 1)
            {
                dfs(i, j);
                V.push_back(cnt);
                cnt = 1;
            }
        }
    }

    cout << *max_element(V.begin(), V.end());
}