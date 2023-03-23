#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n, m, k;
int arr[1010][1010] = {0,};

int main()
{
    STDIO();

    cin >> n >> m >> k;
    arr[0][0] = 1;
    arr[n - 1][m - 1] = k;

    if (k >= n + m - 1)
    {
        cout << "YES" << "\n";
        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                cout << i + j << " ";
            }
            cout << "\n";
        }
    } else
    {
        cout << "NO" << "\n";
    }

    return 0;
}