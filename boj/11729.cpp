#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

void move(int num, int from, int to, int other)
{
    if (num == 0) return;
    move(num - 1, from, other, to);
    cout << from << ' ' << to << '\n';
    move(num - 1, other, to, from);
}

void cnt(int x)
{
    int num = 1;
    while (--x) num = num * 2 + 1;
    cout << num << '\n';
}

int main()
{
    STDIO();
    int N; cin >> N;
    cnt(N);
    move(N, 1, 3, 2);

    return 0;
}