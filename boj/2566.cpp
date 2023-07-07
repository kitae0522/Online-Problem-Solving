#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main()
{
    STDIO();
    array<array<int, 9>, 9> arr{};

    for (int row = 0; row < 9; ++row) for (int col = 0; col < 9; ++col) cin >> arr[row][col];

    auto it = max_element(arr.begin(), arr.end(), [](const array<int, 9> &a, const array<int, 9> &b)
    { return *max_element(a.begin(), a.end()) < *max_element(b.begin(), b.end()); });
    int v = *max_element(it->begin(), it->end());
    int r = distance(arr.begin(), it) + 1;
    int c = distance(it->begin(), max_element(it->begin(), it->end())) + 1;

    cout << v << '\n';
    cout << r << ' ' << c << '\n';
    return 0;
}