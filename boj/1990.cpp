#include <bits/stdc++.h>

using namespace std;

int N, M, Q[15];
bool P[10000001];

void sieve()
{
    for (int i = 2; i * i <= M; ++i)
    {
        if (P[i]) continue;
        for (int j = i * i; j <= min(M, 10000000); j += i) P[j] = true;
    }
}

bool is_palindrome(int number)
{
    int n = 0;
    while (number > 0)
    {
        Q[n++] = number % 10;
        number /= 10;
    }
    for (int i = 0; i < n / 2; ++i) if (Q[i] != Q[n - i - 1]) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;

    sieve();
    for (int i = N; i <= M; ++i)
    {
        if (i >= 10000000) break;
        if (!P[i] && is_palindrome(i)) cout << i << '\n';
    }
    cout << -1;

    return 0;
}
