#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main()
{
    STDIO();
    int N; cin >> N;
    vector<int> V(N);
    for (auto &item: V) cin >> item;
    sort(V.begin(), V.end());

    int target = 1;
    for (int i = 0; i < N; ++i)
    {
        if (V[i] > target) break;
        target += V[i];
    }
    cout << target << '\n';
    return 0;
}