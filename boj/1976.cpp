#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, m;
int parent[201];

int find_root(int x)
{
    if (x == parent[x]) return x;
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
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) parent[i] = i;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1, tmp; j <= n; ++j)
        {
            cin >> tmp;
            if (tmp == 1) union_root(i, j);
        }
    }
    vector<int> v(m);
    for (auto &item: v) cin >> item;
    for (int i = 0; i < m - 1; ++i)
    {
        if (find_root(v[i]) != find_root(v[i + 1]))
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}