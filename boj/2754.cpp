#include <bits/stdc++.h>
using namespace std;

char s[3];
double r;

int main()
{
    scanf("%s", s);
	if (s[0] == 'A') r = 4.0; if (s[0] == 'B') r = 3.0; 
	if (s[0] == 'C') r = 2.0; if (s[0] == 'D') r = 1.0;
    if (s[1] == '+') r += 0.3; if (s[1] == '-') r -= 0.3;
 	printf("%.1lf", r);
	return 0;
}