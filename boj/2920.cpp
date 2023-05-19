#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
#define MAX_LEN 8
using namespace std;

array<int, MAX_LEN> asc = {1, 2, 3, 4, 5, 6, 7, 8};
array<int, MAX_LEN> desc = {8, 7, 6, 5, 4, 3, 2, 1};
array<int, MAX_LEN> arr;

int main()
{
    STDIO();
    for (int &item: arr)
        cin >> item;
    if (arr == asc) cout << "ascending" << endl;
    else if (arr == desc) cout << "descending" << endl;
    else cout << "mixed" << endl;

    return 0;
}
