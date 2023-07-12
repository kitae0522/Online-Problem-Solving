#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<int> V;

int gcd(int x, int y)
{
    return (x % y ? gcd(y, x % y) : y);
}

int get_gcd(int left, int right)
{
    int _gcd = V[left];
    for (int i = left + 1; i <= right; ++i) _gcd = gcd(_gcd, V[i]);
    return _gcd;
}

int f(int left, int right)
{
    if (left == right) return V[left];
    int m1 = left + static_cast<int>(floor((right - left + 1) / 2.0)) - 1;
    int m2 = right - static_cast<int>(ceil((right - left + 1) / 2.0)) + 1;

    int v1 = f(left, m1) + get_gcd(m2, right);
    int v2 = f(m2, right) + get_gcd(left, m1);
    return max(v1, v2);
}

int main()
{
    STDIO();
    int N; cin >> N;
    V.resize(N); for (auto &i: V) cin >> i;
    cout << f(0, static_cast<int>(V.size()) - 1) << '\n';
    return 0;
}