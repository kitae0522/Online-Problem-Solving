#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<bool> v(30, false);

int main()
{
    STDIO();
    for (int i = 1, tmp; i <= 28; ++i)
    {
        cin >> tmp;
        v[tmp] = true;
    }
    for (int i = 1; i <= 30; ++i) if (!v[i]) cout << i << '\n';
    return 0;
}
