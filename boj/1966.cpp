#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define x first
#define y second

using namespace std;

int main()
{
    STDIO();
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for (int i = 0, pri; i < N; ++i)
        {
            cin >> pri;
            q.emplace(pri, i);
            pq.push(pri);
        }
        int cnt = 0;
        while (!q.empty())
        {
            int prrty = q.front().x;
            int idx = q.front().y;
            q.pop();
            if (pq.top() == prrty)
            {
                pq.pop();
                cnt++;
                if (idx == M)
                {
                    cout << cnt << '\n';
                    break;
                }
            }
            else
            {
                q.emplace(prrty, idx);
            }
        }
    }
    return 0;
}