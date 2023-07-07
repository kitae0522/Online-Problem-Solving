#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    while(!(cin >> num1 >> num2).eof()) cout << num1 + num2 << '\n';
	  return 0;
}