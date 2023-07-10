#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
long long R;
vector<int> V;

void merge(int left, int right, int mid)
{
    int i = left;
    int j = mid + 1;
    int k = 0;
    vector<int> tmp(right - left + 1);
    while (i <= mid && j <= right)
    {
        if (V[i] > V[j])
        {
            R += (mid - i + 1);
            tmp[k++] = V[j++];
        }
        else tmp[k++] = V[i++];
    }
    if (mid < i) while (j <= right) tmp[k++] = V[j++];
    else while (i <= mid) tmp[k++] = V[i++];
    for (int n1 = left, n2 = 0; n1 <= right; ++n1) V[n1] = tmp[n2++];
}

void merge_sort(int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, right, mid);
    }
}

int main()
{
    STDIO();
    cin >> N; V.resize(N);
    for (auto &item: V) cin >> item;
    merge_sort(0, N - 1);
    cout << R << '\n';
    return 0;
}