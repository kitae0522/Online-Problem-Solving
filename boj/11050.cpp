#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, k;

int fact(int i)
{
    int result = 1;
    while (i > 0) result *= i--;
    return result;
}

int main()
{
    STDIO();
    cin >> n >> k;
    cout << fact(n) / (fact(k) * fact(n - k));

    return 0;
}
