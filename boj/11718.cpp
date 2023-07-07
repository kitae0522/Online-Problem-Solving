#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main()
{
    STDIO();
    string st;
    while (true)
    {
        getline(cin, st);
        if (st.empty()) break;
        cout << st << '\n';
    }
    return 0;
}