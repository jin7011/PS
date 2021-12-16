#include <iostream>
#include <algorithm>

using namespace std;

int n;
int b;
int cnt;

int main() {

	cin >> n;
	int o = n;

	while (o--) {
		cin >> b; // 의견

		if (b == 1) cnt++; // 귀여우면 +1
	}

	if (cnt > n / 2)
		cout << "Junhee is cute!";
	else
		cout << "Junhee is not cute!";

	return 0;
}