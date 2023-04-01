#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n, res;
vector<int> v;

void solve()
{
    int item = v[v.size() - 1];
    for (int i = v.size() - 2; i >= 0; --i)
    {
        if (v[i] < item)
        {
            res += item - v[i];

        } else
        {
            item = v[i];
        }
    }
}

int main()
{
    STDIO();

    cin >> n;

    for (int i = 0, t; i < n; ++i)
    {
        cin >> t;
        v.push_back(t);
    }
    solve();
    cout << res << endl;


    return 0;
}