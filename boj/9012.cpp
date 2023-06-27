#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int T;

string check_vps(string& str)
{
    int count = 0;
    for (char c: str)
    {
        if (c == '(') count++;
        else if (c == ')')
        {
            count--;
            if (count < 0) return "NO";
        }
    }
    return (count == 0 ? "YES" : "NO");
}

int main()
{
    STDIO();
    cin >> T;
    while (T--)
    {
        string str; cin >> str;
        cout << check_vps(str) << '\n';
    }
    return 0;
}