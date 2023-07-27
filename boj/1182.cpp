#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int N, S, C;

int main()
{
    STDIO();
    cin >> N >> S;
    vector<int> V(N); for (auto &i: V) cin >> i;
    for (int i = 1; i < (1 << N); ++i)
    {
        int R = 0;
        for (int k = 0; k < N; ++k) if (i & (1 << k)) R += V[k];
        if (R == S) C++;
    }
    cout << C << '\n';
    return 0;
}