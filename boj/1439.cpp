#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string st;
int n0, n1;

int main()
{
    STDIO();
    cin >> st;
    for (int i = 0; i < st.length(); ++i)
    {
        if (st[i] != st[i + 1])
        {
            if (st[i] == '0') n0++;
            else n1++;
        }
    }
    cout << min(n0, n1) << '\n';
    return 0;
}