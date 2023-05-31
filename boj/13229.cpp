#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main()
{
    STDIO();
    int N, M;
    cin >> N;
    vector<int> v(N + 1), a(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> v[i];
        a[i] = a[i - 1] + v[i];
    }
    cin >> M;
    while (M--)
    {
        int S, E;
        cin >> S >> E;
        cout << a[E + 1] - a[S] << '\n';
    }
    return 0;
}