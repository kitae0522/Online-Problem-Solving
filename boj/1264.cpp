#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (true)
	{
		string S; getline(cin, S);
		if (S == "#") break;
		int R = 0;	
		for (char C : S)
		{
			if (C == 'a' || C == 'e' || C == 'i' || C == 'o' || C == 'u') R++;
			else if (C == 'A' || C == 'E' || C == 'I' || C == 'O' || C == 'U') R++;
		}
		cout << R << '\n';
	}
	return 0;
}
