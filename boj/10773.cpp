#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int k, res;
stack<int> st;

int main()
{
    STDIO();
    cin >> k;
    while(k--)
    {
        int n; cin >> n;
        if (n == 0) st.pop();
        else st.push(n);
    }
    while(!st.empty())
    {
        res += st.top();
        st.pop();
    }
    cout << res;

    return 0;
}