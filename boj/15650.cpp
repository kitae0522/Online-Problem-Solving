#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

typedef vector<int> vi;

void ncm(vi &arr, vi &res, int idx, int n, int m)
{
    if (m == 0)
    {
        for (int num: res) cout << num << ' ';
        cout << '\n';
        return;
    }
    for (int i = idx; i < n; ++i)
    {
        res.push_back(arr[i]);
        ncm(arr, res, i + 1, n, m - 1);
        res.pop_back();
    }
}

int main()
{
    STDIO();
    int n, m;
    cin >> n >> m;
    vi arr(n), res;
    for (int i = 1; i <= n; ++i) arr[i - 1] = i;
    ncm(arr, res, 0, n, m);
    return 0;
}