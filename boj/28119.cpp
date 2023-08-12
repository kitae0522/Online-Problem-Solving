#include <bits/stdc++.h>

using namespace std;

template<typename T>
using v = vector<T>;
using tiii = tuple<int, int, int>;

int N, M, S, R, P[2020];
v<tiii> T;

int find_root(int x)
{
    if (x == P[x]) return x;
    return P[x] = find_root(P[x]);
}

bool union_root(int x, int y)
{
    x = find_root(x);
    y = find_root(y);
    if (x != y)
    {
        P[x] = y;
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> S;
    T.resize(M);
    iota(P + 1, P + N + 1, 1);
    for (auto &[to, from, weight]: T) cin >> to >> from >> weight;
    sort(T.begin(), T.end(), [](auto x, auto y) { return get<2>(x) < get<2>(y); });
    for (auto [to, from, weight]: T) if (union_root(to, from)) R += weight;
    cout << R << '\n';
    return 0;
}