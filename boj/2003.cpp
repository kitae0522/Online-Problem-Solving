#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int N, M, A[10101], R;

int main()
{
    STDIO();
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int i = 1, j = 1, sum = 0; i <= N; sum -= A[i++])
    {
        while (j <= N && sum < M) sum += A[j++];
        if (sum == M) R++;
    }
    cout << R << '\n';

    return 0;
}