#include <stdio.h>
#include <iostream>

using namespace std;

int a[8] = { 0 };
bool b[9] = { 0 };

void func(int m, int n,int cnt) {

	if (cnt == m) {
		for (int x = 0; x < m; x++)
			cout << a[x]<< " ";
		cout << '\n';

		return;
	}

	for (int x = 1; x <= n; x++) {
		if (!b[x]) {
			b[x] = true;

			if (a[cnt-1] <= x && cnt >= 1) {
				a[cnt] = x;
				func(m, n, cnt + 1);
			}
			else if(cnt == 0){
				a[cnt] = x;
				func(m, n, cnt + 1);
			}

			b[x] = false;
			
		}

	}
}


int main() {

	int n = 0; cin >> n;
	int m = 0; cin >> m;

	func(m, n, 0);

	return 0;
}