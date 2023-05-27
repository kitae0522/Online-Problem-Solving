#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main()
{
    STDIO();
    while (true)
    {
        int m[3];
        cin >> m[0] >> m[1] >> m[2];

        if (!m[0] && !m[1] && !m[2]) break;
        sort(m, m+3);

        if (m[0] * m[0] + m[1] * m[1] == m[2] * m[2]) cout << "right" << '\n';
        else cout << "wrong" << '\n';
    }

    return 0;
}
