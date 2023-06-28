#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main()
{
    STDIO();
    int N; cin >> N;
    deque<int> V(N);
    for (int i = 1; i <= N; ++i) V[i - 1] = i;
    for (int i = 0; i < N; ++i)
    {
        if (i % 2 == 0) cout << V.front() << ' ', V.pop_front();
        else cout << V.back() << ' ', V.pop_back();
    }
    return 0;
}