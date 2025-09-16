#include <bits/stdc++.h>
using namespace std;

int arr[10101];

bool next_permutation(int size)
{
    int i = size - 1;
    while (i > 0 && arr[i - 1] >= arr[i]) i--;
    if (i <= 0) return false;

    int j = size - 1;
    while (arr[j] <= arr[i - 1]) j--;

    swap(arr[i - 1], arr[j]);

    j = size - 1;
    while (i < j) swap(arr[i++], arr[j--]);
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    if (!next_permutation(N)) cout << -1;
    else for (int i = 0; i < N; ++i) cout << arr[i] << ' ';;
    return 0;
}
