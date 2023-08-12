#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, R = 6; cin >> N;
    for (int i = 11; i <= N; ++i) R *= i;
    cout << R << '\n';
    return 0;
}