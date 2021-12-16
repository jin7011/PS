#include <iostream>
#include <stack>
#include <stdlib.h>
#include <functional>

using namespace std;

typedef struct D {
	long long h;
	int i;
}D;

int n;
int arr[500009];

stack <D> stk;

int main() {

	arr[0] = 0;
	stk.push({ 99999999,0 });

	cin >> n;

	for (int x = 1; x <= n; x++) {
		int a;
		cin >> a;

		while (stk.top().h < a) {
			stk.pop();
		}
		arr[x] = stk.top().i;
		stk.push({a,x});

	}

	for (int x = 1; x <= n; x++)
		cout << arr[x] << ' ';


	return 0;
}