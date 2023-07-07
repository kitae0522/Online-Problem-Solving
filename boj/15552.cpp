#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main()
{
    STDIO();
    int T; cin >> T;
    while(T--)
    {
        int num1, num2; cin >> num1 >> num2;
        cout << num1 + num2 << '\n';
    }
    return 0;
}