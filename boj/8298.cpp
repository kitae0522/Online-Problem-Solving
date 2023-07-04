#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int func(int _N, int _K, const string &_S)
{
    int R = 0;
    vector<int> prefix(_N + 1, 0);
    for (int i = 1; i <= _N; ++i)
    {
        prefix[i] = prefix[i - 1] + (_S[i - 1] == 'O' ? 1 : -_K);
        for (int j = 0; j < i; ++j) if (prefix[i] - prefix[j] == _K) R = max(R, i - j);
    }
    return R;
}

int main()
{
    STDIO();
    int N, K; cin >> N >> K;
    string S; cin >> S;
    cout << func(N, K, S) << '\n';
    return 0;
}