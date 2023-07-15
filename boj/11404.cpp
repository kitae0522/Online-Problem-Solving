#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

constexpr int MAX = 1e9;

template<typename T>
using v = vector<T>;

int main()
{
    STDIO();
    int N, M;
    cin >> N >> M;
    v<v<int>> adj(N + 1, v<int>(N + 1, MAX));
    for (int i = 1; i <= N; ++i) adj[i][i] = 0;
    for (int i = 0; i < M; ++i)
    {
        int to, from, weight;
        cin >> to >> from >> weight;
        adj[to][from] = min(adj[to][from], weight);
    }
    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (adj[i][j] == MAX) cout << "0 ";
            else cout << adj[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}