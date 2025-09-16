#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> alpha_count(26, 0);
    string s;

    cin >> s;
    for (auto& c : s)
        if (c - 'a' >= 0) alpha_count[c - 'a']++;
    for (auto& count : alpha_count) cout << count << " ";
    return 0;
}

