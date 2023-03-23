#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_LEN 100
using namespace std;

int alphabet[26];

void prepare()
{
    for (int &i: alphabet)
        i = -1;
}


int main()
{
    STDIO();
    prepare();

    char s[MAX_LEN + 1];
    int idx = 0;

    cin >> s;

    while (s[idx])
    {
        int alpha_idx = s[idx] - 97;
        if (alphabet[alpha_idx] == -1)
            alphabet[alpha_idx] = idx;
        idx++;
    }

    for (int item: alphabet) cout << item << " ";

    return 0;
}