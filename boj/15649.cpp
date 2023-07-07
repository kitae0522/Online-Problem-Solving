#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

constexpr int MAX = 9;
int N, M;
int arr[MAX];
bool visited[MAX];

void dfs(int x)
{
    if (x == M)
    {
        for (int i = 0; i < M; ++i) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr[x] = i;
            dfs(x + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    STDIO();
    cin >> N >> M;
    dfs(0);
    return 0;
}