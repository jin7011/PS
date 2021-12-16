#include <iostream>
#include <memory>

using namespace std;

long long f[91];

long long func2(int n) {

	if (n == 1 || n == 2)
		return 1;

	if (f[n] != 0)
		return f[n];

	else 
		f[n] = func2(n - 2) + func2(n - 1);
		return f[n];
}

int main() {

	int n; cin >> n;

		cout << func2(n) << " ";

	return 0;
}