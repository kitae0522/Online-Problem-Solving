#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_LEN 100
using namespace std;

int pow_array[MAX_LEN + 1];

void prepare()
{
    for (int i = 0; i < MAX_LEN; ++i)
        pow_array[i] = (i + 1) * (i + 1);
}

int main()
{
    STDIO();
    prepare();

    int n, m;
    int res1 = 0, res2;
    bool isUpdated = false;

    cin >> n >> m;

    for (int i = 0; i < MAX_LEN; ++i)
    {
        if ((n <= pow_array[i]) && (pow_array[i] <= m))
        {
            if (!isUpdated)
                res2 = pow_array[i];
            res1 += pow_array[i];
            isUpdated = true;
        }
    }

    if (!isUpdated)
        cout << -1;
    else
        cout << res1 << "\n" << res2;

    return 0;
}
