#include <iostream>
#include <string>
#include <deque>
#include <stdio.h>

using namespace std;

int n = 0;
string str;
deque <int> dque;

int main() {

	cin >> n;
	int t = 0;

	while (n--) {
		cin >> str;

		if (str[0] == 'p') {
			if (str[1] == 'u') { //push_front  &   push_back
				if (str[5] == 'f') {
					scanf_s("%d", &t);
					dque.push_front(t);
				}
				else {
					scanf_s("%d", &t);
					dque.push_back(t);
				}
			}
			else if (str[1] == 'o') {
				if (str[4] == 'f') {
					if (dque.size() == 0)
						cout << "-1\n";
					else {
						cout << dque.front()<< '\n';
						dque.pop_front();
					}
				}
				else {
					if (dque.size() == 0)
						cout << "-1\n";
					else {
						cout << dque.back()<< '\n';
						dque.pop_back();
					}
				}
			}
		}

		if (str[0] == 's') cout << dque.size()<<'\n';

		if (str[0] == 'e') {
			if (dque.size() == 0) cout << "-1\n";
			else
				cout << dque.empty() << '\n';
		}

		if (str[0] == 'f') {
			if (dque.size() == 0) cout << "-1\n";
			else cout << dque.front() << "\n";
		}
		if (str[0] == 'b') {
			if (dque.size() == 0) cout << "-1\n";
			else cout << dque.back() << '\n';
		}

	}

	return 0;
}