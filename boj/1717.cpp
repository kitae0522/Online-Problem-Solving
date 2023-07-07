#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_LEN 1010101
using namespace std;

int n, m;
int parent[MAX_LEN];
int node_rank[MAX_LEN];

void init()
{
    for (int i = 0; i < MAX_LEN; ++i)
        parent[i] = i;
}

int find_root(int x)
{
    if (x == parent[x]) return x;
    return parent[x] = find_root(parent[x]);
}

void union_root(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    if (x != y)
    {
        if (node_rank[x] < node_rank[y]) parent[x] = y;
        else parent[y] = x;

        if (node_rank[x] == node_rank[y]) node_rank[x]++;
    }
}

int main()
{
    STDIO();
    init();

    cin >> n >> m;

    for (int i = 0, o, a, b; i < m; ++i)
    {
        cin >> o >> a >> b;
        switch (o)
        {
            case 0:
                union_root(a, b);
                break;
            case 1:
                int tmp1, tmp2;
                tmp1 = find_root(a);
                tmp2 = find_root(b);
                cout << (tmp1 == tmp2 ? "YES" : "NO") << "\n";
                break;
            default:
                break;
        }
    }

    return 0;
}