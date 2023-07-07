#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

template<typename T>
using v = vector<T>;
using ll = long long;
using tiii = tuple<int, int, int>;
using tiiii = tuple<int, int, int, int>;

v<tiii> G;
v<tiiii> T;
ll R, C;
int parent[101'010];

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

int calc_cost(tiiii p1, tiiii p2)
{
    return min({abs(get<0>(p1) - get<0>(p2)),
                abs(get<1>(p1) - get<1>(p2)),
                abs(get<2>(p1) - get<2>(p2))});
}

void add_edge(int p1, int p2)
{
    int weight = calc_cost(T[p1], T[p2]);
    G.emplace_back(get<3>(T[p1]), get<3>(T[p2]), weight);
}

int main()
{
    STDIO();
    int N; cin >> N;

    T.reserve(N);
    for (int i = 1; i <= N; ++i) parent[i] = i;
    for (int i = 0; i < N; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        T.emplace_back(x, y, z, i);
    }

    // x 기준으로 정렬 후 삽입
    sort(T.begin(), T.end(), [](auto p1, auto p2) { return get<0>(p1) < get<0>(p2); });
    for (int i = 0; i < N - 1; ++i) add_edge(i, i + 1);
    // y 기준으로 정렬 후 삽입
    sort(T.begin(), T.end(), [](auto p1, auto p2) { return get<1>(p1) < get<1>(p2); });
    for (int i = 0; i < N - 1; ++i) add_edge(i, i + 1);
    // z 기준으로 정렬 후  삽입
    sort(T.begin(), T.end(), [](auto p1, auto p2) { return get<2>(p1) < get<2>(p2); });
    for (int i = 0; i < N - 1; ++i) add_edge(i, i + 1);

    sort(G.begin(), G.end(), [](tiii p1, tiii p2) { return get<2>(p1) < get<2>(p2); });
    for (auto &relation: G)
    {
        int to, from, weight;
        tie(to, from, weight) = relation;
        if (find_root(to) != find_root(from))
        {
            union_root(to, from);
            R += weight;
            if (++C == N - 1) break;
        }
    }
    cout << R << '\n';
    return 0;
}
