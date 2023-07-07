#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main()
{
    STDIO();
    string st; cin >> st;
    cout << count_if(st.begin(), st.end(), [](char s) { return s == 'a' || s == 'i' || s == 'u' || s == 'e' || s == 'o'; }) << '\n';
    return 0;
}