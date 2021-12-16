#include <iostream>
#include <memory>
#include <stdio.h>
#include <stack>
#include <string>
using namespace std;

int n = 0;
string str;

int main() {

	stack <int> stk;

	cin >> n;
	int t = 0;
	while (n--) {

		cin >> str;

		if (str[0] == 'p') {
			if (str[1] == 'u') {
				scanf_s("%d", &t);
				stk.push(t);
			}
			else {
				if (stk.empty() == 1)
					printf("-1\n");
				else {
					printf("%d\n", stk.top());
					stk.pop();
				}
			}
		}
		if (str[0] == 't') {
			if (stk.empty() == 1)
				printf("-1\n");
			else
			printf("%d\n", stk.top());
		}
		if (str[0] == 'e') {
			printf("%d\n", stk.empty());
		}
		if (str[0] == 's') {
			printf("%d\n", stk.size());
		}

	}

	return 0;
}