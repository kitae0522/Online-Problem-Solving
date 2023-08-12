#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    set<int> A;
    for (int i = 1, x; i <= N; ++i)
    {
        cin >> x;
        A.insert(x);
    }
    for (int i = 1, x; i <= M; ++i)
    {
        cin >> x;
        if (A.count(x)) A.erase(x);
    }
    cout << A.size() << '\n';
    for (auto i: A) cout << i << ' ';
    return 0;
}