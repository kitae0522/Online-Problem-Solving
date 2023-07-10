#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> V;

int f(int left, int right)
{
    if (left > right) return 0;
    if (left == right) return V[left];
    int mid = (left + right) / 2;
    int res = V[mid], cnt = 1, mn = V[mid];
    int i = mid - 1, j = mid + 1;
    while (left <= i && j <= right)
    {
        if (V[i] > V[j]) cnt++, mn = min(mn, V[i--]);
        else cnt++, mn = min(mn, V[j++]);
        res = max(res, cnt * mn);
    }
    while(left <= i)
    {
        cnt++; mn = min(mn, V[i--]);
        res = max(res, cnt * mn);
    }
    while(j <= right)
    {
        cnt++; mn = min(mn, V[j++]);
        res = max(res, cnt * mn);
    }
    res = max(res, f(left, mid - 1));
    res = max(res, f(mid + 1, right));
    return res;
}

int main()
{
    STDIO();
    cin >> N; V.resize(N);
    for (auto &i: V) cin >> i;
    cout << f(0, N - 1) << '\n';
    return 0;
}