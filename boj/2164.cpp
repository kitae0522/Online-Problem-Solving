#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

int N;
queue<int> cq;

int main()
{
    STDIO();

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cq.push(i);
    while (cq.size() > 1)
    {
        cq.pop();
        cq.push(cq.front());
        cq.pop();
    }
    cout << cq.front() << '\n';
    return 0;
}
