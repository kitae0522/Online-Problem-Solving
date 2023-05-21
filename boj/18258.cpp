#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

typedef long long ll;

int T, N;
string st;
queue<int> q;

int main()
{
    STDIO();
    cin >> T;
    while (T--)
    {
        cin >> st;
        if (st == "push")
        {
            cin >> N;
            q.push(N);
        } else if (st == "pop")
        {
            if (!q.empty())
            {
                cout << q.front() << '\n';
                q.pop();
            } else
            {
                cout << -1 << '\n';
            }
        } else if (st == "size")
        {
            cout << q.size() << '\n';
        } else if (st == "empty")
        {
            if (!q.empty()) cout << 0 << '\n';
            else cout << 1 << '\n';
        } else if (st == "front")
        {
            if (!q.empty()) cout << q.front() << '\n';
            else cout << -1 << '\n';
        } else if (st == "back")
        {
            if (!q.empty()) cout << q.back() << '\n';
            else cout << -1 << '\n';
        }
    }

    return 0;
}
