#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, X, R;

int main()
{
    STDIO();
    cin >> N;
    vector<int> V(N);
    for (auto &item: V) cin >> item;
    cin >> X;
    for (auto &item: V) if (item == X) R++;
    cout << R << '\n';
    return 0;
}