#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

unordered_map<string, int> M;
vector<string> V;

int main()
{
    STDIO();
    int N, K; cin >> N >> K;
    for (int i = 1; i <= N + K; ++i)
    {
        string S; cin >> S; M[S]++;
        if (M[S] > 1) V.push_back(S);
    }
    sort(V.begin(), V.end());
    cout << V.size() << '\n';
    for (auto &i: V) cout << i << '\n';
    return 0;
}