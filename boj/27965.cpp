#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

typedef long long ll;

ll n, k, ans;

ll get_len_num(ll num)
{
    int result = 0;
    while (num != 0)
    {
        num /= 10;
        result++;
    }
    return result;
}

int main()
{
    STDIO();
    cin >> n >> k;
    for (ll i = 1; i <= n; ++i)
    {
        ll len_num = get_len_num(i);
        while (len_num--) ans *= 10;
        ans += i;
        ans %= k;
    }
    cout << ans << '\n';

    return 0;
}
