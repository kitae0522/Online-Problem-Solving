#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int cnt;

int recursion(const string &s, int l, int r)
{
    cnt++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int is_palindrome(const string &s)
{
    return recursion(s, 0, s.size() - 1);
}

int main()
{
    STDIO();
    int T;
    cin >> T;
    while (T--)
    {
        string s; cin >> s;
        cout << is_palindrome(s) << ' ' << cnt << '\n';
        cnt = 0;
    }
}