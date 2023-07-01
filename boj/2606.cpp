#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int parent[101];
int V, E, R;

int find_root(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = find_root(parent[x]);
}

void union_root(int x, int y)
{
    x = find_root(x);
    y = find_root(y);
    if (x < y) parent[y] = x;
    else parent[x] = y;
}

int main()
{
    STDIO();
    cin >> V >> E;
    for (int i = 1; i <= V; ++i) parent[i] = i;
    for (int i = 0; i < E; ++i)
    {
        int to, from;
        cin >> to >> from;
        union_root(to, from);
    }
    for (int i = 2; i <= V; ++i) if (find_root(1) == find_root(i)) R++;
    cout << R << '\n';
    return 0;
}