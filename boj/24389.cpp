#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n; m = -n;
    for (int i=0; i<32; ++i)
    {
        int pn = (1 << i) & n;
        int pm = (1 << i) & m;
        r += (pn ^ pm) ? 1 : 0;
    }
    cout << r;

    return 0;
}
