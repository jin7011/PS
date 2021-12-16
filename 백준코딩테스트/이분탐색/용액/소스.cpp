#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <math.h>

using namespace std;

int n;
long long* a;
int mini;
int maxi;
long long ans;
int resL;
int resR;
long long mid;

int main() {
	cin >> n;

	a = new long long[n + 1];

	for (int x = 0; x < n; x++)
		cin >> a[x];

	sort(a, a + n);

	mini = 0;
	maxi = n - 1;
	resL = mini;
	resR = maxi;
	ans = abs(a[resL] + a[resR]);
	
	while (mini < maxi) {

		mid = a[mini] + a[maxi];

		if (mid > 0) // 양수라면
		{
			if (ans > abs(mid)) {
				resL = mini;
				resR = maxi;
				ans = abs(mid);
			}
			maxi--;
		}

		else// 음수라면 
		{
			if (ans > abs(mid)) {
				resL = mini;
				resR = maxi;
				ans = abs(mid);
			}
			mini++;
		}
	}

	cout << a[resL] << ' ' << a[resR];

	return 0;
}