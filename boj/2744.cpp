#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main()
{
    STDIO();
    string st; cin >> st;
    for (char &c: st)
    {
        if (65 <= c && c <= 90) c += 32;
        else c -= 32;
    }
    cout << st << '\n';
    return 0;
}