#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    while (true)
    {
        cin >> N >> M;
        if (!N && !M) break;
        cout << (N > M ? "Yes" : "No") << '\n';
    }
    return 0;
}