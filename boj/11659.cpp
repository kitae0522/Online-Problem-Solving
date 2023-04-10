#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n, t, a, b, arr[101010];
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

    cin >> n >> t;
    v.reserve(n + 1);

    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    summation();

    while (t--)
    {
        cin >> a >> b;
        cout << v[b] - v[a-1] << "\n";
    }

    return 0;
}