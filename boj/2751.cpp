#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

void merge(vector<int>& arr, int left, int right, int mid)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> v1(n1), v2(n2);
    for (int i = 0; i < n1; ++i) v1[i] = arr[left + i];
    for (int i = 0; i < n2; ++i) v2[i] = arr[mid + i + 1];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (v1[i] <= v2[j]) arr[k] = v1[i++];
        else arr[k] = v2[j++];
        ++k;
    }
    while(i < n1) arr[k++] = v1[i++];
    while(j < n2) arr[k++] = v2[j++];
}

void merge_sort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, right, mid);
    }
}

int main()
{
    STDIO();
    int N; cin >> N;
    vector<int> V(N);
    for(auto &item: V) cin >> item;
    merge_sort(V, 0, N - 1);
    for(auto &item: V) cout << item << '\n';
    return 0;
}