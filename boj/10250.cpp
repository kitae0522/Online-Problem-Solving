#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int main()
{
    STDIO();
    int T; cin >> T;
    while(~--T)
    {
        int H,W,N; cin >> H >> W >> N;
        if (N%H) printf("%d%02d\n", N%H, N/H+1);
        else printf("%d%02d\n", H, N/H);
    }
    return 0;
}