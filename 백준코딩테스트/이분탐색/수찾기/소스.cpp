#include <iostream>
#include <algorithm>

using namespace std;

int a[1000001];
int n,m,k;

void func(int k, int left, int right) {

	int middle = (left + right) / 2;

	if (middle == k) {
		cout << 1 << '\n';
		return;
	}

		if (left > right) {
			cout << 0 << '\n';
			return;
		}
		else if (middle < k) // the num what we wanna find is on the right
		{
			func(k, middle + 1, right);
		}
		else if(middle > k)// on the left
		{
			func(k, left, middle - 1);
		}

}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int x = 0; x < n; x++)
		cin >> a[x];

	sort(a, a+n);

	cin >> m;

	while (m--) {
		cin >> k;
		func(k, a[0], a[n - 1]);
	}

	return 0;
}