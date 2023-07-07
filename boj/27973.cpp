#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

int T, CMD, X;
ll p1 = 1, p2 = 1'234'567'890'123, bias = 1;

int main()
{
    STDIO();
    cin >> T;
    while (T--)
    {
        cin >> CMD;
        switch (CMD)
        {
            case 0:
                cin >> X;
                p1 += X;
                p2 += X;
                break;
            case 1:
                cin >> X;
                p1 *= X;
                p2 *= X;
                bias *= X;
                break;
            case 2:
                cin >> X;
                p1 += X * bias;
                break;
            case 3:
                cout << p1 << '\n';
                break;
            default:
                continue;
        }
    }

    return 0;
}
