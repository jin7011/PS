#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[10000001];
int mini, maxi, mid;
int lim;
int res;

int main() {

	cin >> n;

	for (int x = 0; x < n; x++) {
		cin >> a[x];
		maxi = max(maxi, a[x]);
	}

	cin >> lim;

	mini = 0;

	int sum = 0;

	while (mini <= maxi) {

		sum = 0;
		mid = (mini + maxi + 1) / 2;

		for (int x = 0; x < n; x++)
		{
			if (a[x] < mid)
				sum += a[x];
			else
				sum += mid;
		}

		if (sum > lim) {
			maxi = mid - 1;
		}
		else
		{
			res = mid;
			mini = mid + 1;
		}
	}

	cout << res;

	return 0;
}