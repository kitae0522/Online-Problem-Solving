#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int t, l, n, x, y;

int main()
{
    STDIO();
    cin >> t;
    while (t--)
    {
        cin >> l >> n;
        for (int i = 0, tmp; i < n; ++i)
        {
            cin >> tmp;
            x = max(x, min(tmp, l - tmp));
            y = max(y, max(tmp, l - tmp));
        }
        cout << x << ' ' << y << '\n';
        x = y = 0;
    }
    return 0;
}