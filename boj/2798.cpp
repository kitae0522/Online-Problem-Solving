#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, m;
vector<int> v;

int main()
{
    STDIO();
    cin >> n >> m;
    v.resize(n);
    for (auto &i: v) cin >> i;
    int result = 0;
    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
            for (int k = j + 1; k < n; k++)
            {
                int sum = v[i] + v[j] + v[k];
                if (sum <= m) result = max(result, sum);
            }

    cout << result << endl;

    return 0;
}
