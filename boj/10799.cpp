#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string input;
    cin >> input;

    stack<char> s;
    int c = 0;
    for (int i = 0; i < input.size(); ++i)
    {
        char curr = input[i];
        char next = input[i + 1];

        if (curr == '(' && next == ')')
        {
            c += s.size();
            i++;
        }
        else
        {
            if (curr == '(') s.push('(');
            else if (curr == ')')
            {
                c++;
                s.pop();
            }
        }
    }

    cout << c << '\n';
}

