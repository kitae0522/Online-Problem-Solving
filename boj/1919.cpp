#include <bits/stdc++.h>
using namespace std;

int fn(const string& victim, const string& target)
{
    int victim_alpha_count[26] = {};
    int target_alpha_count[26] = {};

    int result = 0;

    for (auto& vc : victim) victim_alpha_count[vc - 'a']++;
    for (auto& tc : target) target_alpha_count[tc - 'a']++;

    for (int i = 0; i < 26; ++i)
    {
        result += abs(victim_alpha_count[i] - target_alpha_count[i]);
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string vs, ts;
    cin >> vs >> ts;

    cout << fn(vs, ts) << '\n';
}
