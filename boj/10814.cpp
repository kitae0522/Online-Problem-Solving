#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
vector<tuple<int, string, int>> v;

int main()
{
    STDIO();
    cin >> n;
    v.reserve(n);
    for(int i=1; i<=n; ++i)
    {
        int age; string name;
        cin >> age >> name;
        v.emplace_back(age, name, i);
    }
    sort(v.begin(), v.end(), [](auto x, auto y){
        if (get<0>(x) == get<0>(y))
            return get<2>(x) < get<2>(y);
        return get<0>(x) < get<0>(y);
    });

    for (const auto& t: v) cout << get<0>(t) << " " << get<1>(t) << "\n";
}
