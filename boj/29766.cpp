#include <bits/stdc++.h>
using namespace std;

int R;
string S;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S;
    int idx = 0;
    while ((idx = S.find("DKSH", idx)) != string::npos) R++, idx += 4;
    cout << R;
}

