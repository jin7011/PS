#include <iostream>
#include <algorithm>
#include <stack>
#include <stdio.h>

using namespace std;

stack <int> stk;

int n = 0;
int a[1000001] = { 0 };
int b[1000001] = { 0 };
int i = 0; // a
int x = 0; // b
int c = 0;
string op;

int Compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {

	cin >> n;
	
	for (int x = 0; x < n; x++) {
		cin >> a[x];
		b[x] = a[x];
	}

	qsort(b,n,sizeof(int),Compare);

	// stack에 넣을 떄 오름정리된 b 수열을 사용한다.
	// 넣기 전에 비교하려면 a수열을 사용.

	while (i != n) {

		if (a[i] >= b[x] && b[x] != 0) {
			stk.push(b[x]);
			op += '+';
			c++;
			x++;
		}
		if (a[i] == stk.top()) {
			stk.pop();
			op += '-';
			c++;
			i++;
		}
		if(stk.size() >0)
		if (a[i] < stk.top()) {
			printf("NO\n");
			return 0;
		}
			
	}

	for (int x = 0; x < op.length(); x++)
		cout << op[x] << '\n';

	return 0;
}