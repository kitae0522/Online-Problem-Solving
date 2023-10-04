#include <bits/stdc++.h>

using namespace std;

int N, M, I[32323];
vector<int> G[32323];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= M; ++i)
    {
        int s, e; cin >> s >> e;
        G[s].push_back(e);
        I[e]++;
    }
    priority_queue<int, vector<int>, greater<>> Q;
    for (int i = 1; i <= N; ++i) if (!I[i]) Q.push(i);
    while (!Q.empty())
    {
        int curr = Q.top(); Q.pop();
        cout << curr << " ";
        for (auto i: G[curr]) if (!--I[i]) Q.push(i);
    }

    return 0;
}
