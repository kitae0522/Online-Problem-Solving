#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> n(3);
    for (auto &item : n) cin >> item;
    int r = n[2] % 2 ? n[0] ^ n[1] : n[0];
    cout << r;
}
