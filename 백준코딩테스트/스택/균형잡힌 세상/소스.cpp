#include <stack>
#include <string>
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

stack <char> stk;
string str;

int func(string str) {

	int len = stk.size();

	for (int x = 0; x < len; x++) //stack 청소
		stk.pop();

	for (int x = 0; x <str.length(); x++) {

		if (str[x] == '(') {
			stk.push('(');
		}
		if (str[x] == '[') {
			stk.push('[');
		}
		if (str[x] == ')') {
			if (stk.size() == 0) 
				return 0;
			if (stk.top() == '(')
				stk.pop();
			else return 0;
		}
		if (str[x] == ']') {
			if (stk.size() == 0) 
				return 0;
			if (stk.top() == '[')
				stk.pop();
			else return 0;
		}
	}

	if (stk.empty() == 1)
		return 1; //yes
	else if (stk.empty() == 0 && stk.top() == '(' || stk.top() == '[') 
		return 0;

}

int main() {

	while (1) {

		int res = 0;
		getline(cin, str);

		//exit condition
		if (str[0] == '.') return 0;

		res = func(str); //성공하면 1 return 

		if (res == 1) 
			cout << "yes\n";
		else
			cout << "no\n";

	}

	return 0;
}