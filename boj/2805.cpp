#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

using ll = long long;

int main()
{
    STDIO();
    int P, Q; cin >> P >> Q;
    vector<int> T(P); for (auto &i: T) cin >> i;
    int L = 0, R = *max_element(T.begin(), T.end());
    while (L <= R)
    {
        int M = (L + R) / 2;
        ll S = 0;
        for (int i = 0; i < P; i++) if (T[i] > M) S += T[i] - M;
        if (S >= Q) L = M + 1;
        else R = M - 1;
    }
    cout << L - 1 << '\n';
    return 0;
}