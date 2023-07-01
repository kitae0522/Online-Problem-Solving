#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

template<typename T>
using v = vector<T>;
using tiii = tuple<int, int, int>;
using ll = long long;

ll R, CNT;
int parent[1'010];
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
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) parent[i] = i;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int weight;
            cin >> weight;
            if (j > i) T.emplace_back(i, j, weight);
        }
    }
    sort(T.begin(), T.end(), [](auto x, auto y)
    { return get<2>(x) < get<2>(y); });
    for (auto &relation: T)
    {
        int to, from, weight;
        tie(to, from, weight) = relation;
        if (find_root(to) != find_root(from))
        {
            union_root(to, from);
            R += weight;
            if (++CNT == N - 1) break;
        }
    }
    cout << R << '\n';
    return 0;
}