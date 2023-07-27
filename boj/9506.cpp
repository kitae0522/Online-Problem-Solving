#include <bits/stdc++.h>

#define STDIO() ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

void f(int N)
{
    int S = 0;
    vector<int> V;
    for(int i = 1; i < N; ++i)
    {
        if (N % i == 0) {
            S += i;
            V.push_back(i);
        }
    }
    if(S == N)
    {
        cout << N << " = ";
        for(size_t i = 0; i < V.size(); ++i)
        {
            cout << V[i];
            if (i != V.size() - 1) cout << " + ";
        }
        cout << "\n";
    }
    else
    {
        cout << N << " is NOT perfect.\n";
    }
}

int main()
{
    STDIO();
    while (true)
    {
        int N; cin >> N;
        if (N == -1) break;
        f(N);
    }
    return 0;
}