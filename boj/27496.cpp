#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n, l, arr[1010101], res;
vector<int> v;

void summation()
{
    v.push_back(0);
    for (int i = 0; i < n; ++i)
        v.push_back(v[i] + arr[i]);
}

int main()
{
    STDIO();

    cin >> n >> l;
    for (int i = 0, a_i; i < n; ++i)
    {
        cin >> a_i;
        arr[i] += a_i;
        arr[i + l] -= a_i;
    }

    summation();
    for (int item: v) res += 129 <= item && item <= 138;
    cout << res << endl;

    return 0;
}