#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n, m, t, x01, x02, y01, y02;
vector<vector<int>> v, p_s;

int main()
{
    STDIO();

    cin >> n >> m;
    v.resize(n + 1, vector<int>(m + 1, 0));
    p_s.resize(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> v[i][j];
            p_s[i][j] = p_s[i - 1][j] + p_s[i][j - 1] - p_s[i - 1][j - 1] + v[i][j];
        }
    }

    cin >> t;
    while (t--)
    {
        cin >> x01 >> y01 >> x02 >> y02;
        cout << p_s[x02][y02] - p_s[x01 - 1][y02] - p_s[x02][y01 - 1] + p_s[x01 - 1][y01 - 1] << "\n";
    }

    return 0;
}