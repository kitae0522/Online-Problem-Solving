#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

unordered_map<string, bool> m;
int cnt;

int main()
{
    STDIO();
    int N, M; cin >> N >> M;
    while (N--)
    {
        string st; cin >> st;
        m[st] = true;
    }
    while (M--)
    {
        string st; cin >> st;
        if (m[st]) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
