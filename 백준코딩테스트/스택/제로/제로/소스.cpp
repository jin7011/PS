#include <iostream>
#include <algorithm>
#include <stack>
#include <stdio.h>
using namespace std;

int k = 0;
int n = 0;

int main() {

	stack <int> stk;

	cin >> k;

	int sum = 0;

	while (k--) {
		cin >> n;

		if(n != 0) {
			stk.push(n);
		}
		else {
			stk.pop();
		}

	}
	
	while (stk.empty() != 1) {
		sum += stk.top();
		stk.pop();
	}

	cout << sum;

	return 0;
}