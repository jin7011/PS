#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int k = 0;

string str;
stack <string> stk;

int main() {

	int n = 0; cin >> n;
	int k = 0;

	while (n--) {
		int len = stk.size();

		for (int x = 0; x < len; x++) //stack 청소
			stk.pop();

		int k = 0;

		cin >> str;

		for (int x = 0; x < str.length(); x++) {

			if (str[x] == '(') {
				stk.push("(");
			}
			else { //          ' )' 이 있을 때,
				if (stk.empty() == 1) {
					cout << "NO\n";
					k++;
					break;
				}
				else
					stk.pop();
			}

		}
		if (stk.empty() == 1 && k==0)
			cout << "YES\n";
		else if ( stk.empty() == 0 && stk.top() == "(" ) //
			cout << "NO\n";
	}

	return 0;
}