#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 1, t; i <= N * N; ++i)
    {
        cin >> t;
        pq.push(t);
        if (pq.size() > N) pq.pop();
    }
    cout << pq.top();
    return 0;
}