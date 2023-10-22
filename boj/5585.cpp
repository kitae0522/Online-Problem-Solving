#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> Y = {500, 100, 50, 10, 5, 1};
    int N, R = 0; cin >> N; N = 1000 - N;
    for (auto M: Y)
    {
        if (N >= M)
        {
            R += N / M;
            N %= M;
        }
    }
    cout << R;
    return 0;
}
