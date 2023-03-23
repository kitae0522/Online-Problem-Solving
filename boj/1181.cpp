#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n;
string s;
vector<string> v;

bool cmp(string x1, string x2)
{
    if (x1.length() != x2.length())
        return x1.length() < x2.length();
    for (int i = 0; i < x1.length(); ++i)
    {
        if (x1[i] != x2[i])
            return x1[i] < x2[i];
    }
    return false;
}

int main()
{
    STDIO();

    cin >> n;
    while (n--)
    {
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    v.erase(unique(v.begin(), v.end()), v.end());
    for (string item: v) cout << item << "\n";

    return 0;
}