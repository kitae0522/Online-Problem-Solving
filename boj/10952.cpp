#include <iostream>
using namespace std;

int main() {
    while(1) 
    {
        int num1, num2;
        cin >> num1 >> num2;
        if(num1 == 0 && num2 == 0) break;
        else cout << num1 + num2 << '\n';
    }
	return 0;
}