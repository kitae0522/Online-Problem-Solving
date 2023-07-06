#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

constexpr int dx[] = {0, 0, -1, 1};
constexpr int dy[] = {1, -1, 0, 0};

template<typename T>
using v = vector<T>;

int N, M, R;
v<v<char>> A;
v<v<bool>> V;

void dfs(int x, int y)
{
    // for debug
    // cout << x << ", " << y << " | " << A[x][y] << '\n';
    V[x][y] = true;
    for (int i = 0; i < 4; ++i)
    {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (0 <= nx && nx < N && 0 <= ny && ny < M)
        {
            if (A[nx][ny] != 'X' && A[nx][ny] != 'I' && !V[nx][ny])
            {
                if (A[nx][ny] == 'P') R++;
                dfs(nx, ny);
            }
        }
    }
}

int main()
{
    STDIO();
    cin >> N >> M;
    A.resize(N, v<char>(M));
    V.resize(N, v<bool>(M, false));
    int X, Y;
    for (int i = 0; i < N; ++i)
    {
        for(int j =0; j<M;++j)
        {
            cin >> A[i][j];
            if (A[i][j] == 'I') X = i, Y = j;
        }
    }
    dfs(X, Y);
    if (R) cout << R << '\n';
    else cout << "TT" << '\n';
    return 0;
}