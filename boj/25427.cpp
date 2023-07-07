#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

typedef long long ll;

ll D, K, S, H;

int main()
{
    STDIO();
    int n; string st; cin >> n >> st;

    if (st[0] == 'D') D = 1;

    for (int i = 1; i < n; ++i)
    {
        if (st[i] == 'D') D++;
        else if (st[i] == 'K') K += D;
        else if (st[i] == 'S') S += K;
        else if (st[i] == 'H') H += S;
    }

    cout << H << '\n';

    return 0;
}