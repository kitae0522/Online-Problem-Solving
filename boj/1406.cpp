#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string input; cin >> input;
	int command_count; cin >> command_count;

	list<char> str_list;
	for (auto &c: input) str_list.push_back(c);
	list<char>::iterator iter = str_list.end();

	while (command_count--) {
		char command; cin >> command;

		if (command == 'L') {
			if (iter != str_list.begin()) iter--;
		}
		else if (command == 'D') {
			if (iter != str_list.end()) iter++;
		}
		else if (command == 'B') {
			if (iter != str_list.begin()) iter = str_list.erase(--iter);
		}
		else if (command == 'P') {
			char new_character; cin >> new_character;
			str_list.insert(iter, new_character);
		}
	}

	for (auto &c: str_list) {
		cout << c;
	}
}