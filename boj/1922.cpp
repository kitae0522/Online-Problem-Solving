#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

template<typename T>
using v = vector<T>;
using tiii = tuple<int, int, int>;

int parent[1'010];
int V, E, R;
v<tiii> T;

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
        int to, from, weight;
        cin >> to >> from >> weight;
        T.emplace_back(to, from, weight);
    }
    sort(T.begin(), T.end(), [](auto x, auto y) { return get<2>(x) < get<2>(y); });
    for (int i = 0; i < E; ++i)
    {
        int to, from, weight;
        tie(to, from, weight) = T[i];
        if (find_root(to) != find_root(from))
        {
            union_root(to, from);
            R += weight;
        }
    }
    cout << R << '\n';
    return 0;
}