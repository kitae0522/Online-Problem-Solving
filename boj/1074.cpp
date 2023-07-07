#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, R, C, S;

void f(int x, int y, int size)
{
    if (x == C && y == R)
    {
        cout << S << '\n';
        return;
    }

    if (C < x + size && R < y + size && C >= x && R >= y)
    {
        f(x, y, size / 2);
        f(x + size / 2, y, size / 2);
        f(x, y + size / 2, size / 2);
        f(x + size / 2, y + size / 2, size / 2);
    }
    else S += size * size;
}

int main()
{
    STDIO();
    cin >> N >> R >> C;
    f(0, 0, 1 << N);
    return 0;
}