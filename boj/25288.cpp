#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

int N;
string S;

int main()
{
    STDIO();
    cin >> N >> S;
    for(int i=1; i<=N; ++i) cout << S;
    return 0;
}
