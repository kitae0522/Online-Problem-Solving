#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    vector<string> V;
    map<string, int> C;
    for (int i = 0; i < N; ++i)
    {
        string st; cin >> st;
        if (st.size() >= M) V.push_back(st), C[st]++;
    }
    sort(V.begin(), V.end(), [&C](auto x, auto y){
        if (C[x] != C[y]) return C[x] > C[y];
        if (x.size() != y.size()) return x.size() > y.size();
        return x < y;
    });
    for (int i = 0; i < V.size(); ++i) if (i == 0 || V[i - 1] != V[i]) cout << V[i] << '\n';
    return 0;
}