#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int main()
{
    STDIO();
    int N; cin >> N;
    for (int i = 0; N; ++i, N >>= 1) if ((N & 1) == 1) cout << i << ' ';
    return 0;
}