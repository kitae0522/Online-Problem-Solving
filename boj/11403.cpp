#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

constexpr int MAX = 1e9;

template<typename T>
using v = vector<T>;

int main()
{
    STDIO();
    int N; cin >> N;
    v<v<int>> adj(N + 1, v<int>(N + 1, MAX));
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) cin >> adj[i][j];
    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                if (adj[i][k] == 1 && adj[k][j] == 1) adj[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
