#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, K, A[202020], S[202020], R;
map<int, int> C;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int i = 1; i <= N; ++i) S[i] = S[i - 1] + A[i];
    for (int i = 0; i <= N; ++i) R += C[S[i] - K], C[S[i]]++;
    cout << R << '\n';
    return 0;
}