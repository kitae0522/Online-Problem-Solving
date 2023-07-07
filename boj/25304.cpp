#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int x, t, a, b;

int main()
{
    STDIO();

    cin >> x >> t;
    while(t--)
    {
        cin >> a >> b;
        x -= a * b;
    }

    cout << (x == 0 ? "Yes" : "No") << "\n";

    return 0;
}