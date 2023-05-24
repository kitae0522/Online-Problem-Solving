#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main()
{
    STDIO();

    int n, a, b;
    cin >> n >> a >> b;
    if (a < b) cout << "Bus";
    else if (a > b) cout << "Subway";
    else cout << "Anything";

    return 0;
}
