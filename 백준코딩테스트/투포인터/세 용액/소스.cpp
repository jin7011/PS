#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <functional>

using namespace std;

vector<long long> vec;
long long res=99999999999999999;
int n;
bool flag = 0;

typedef struct D {
	int l, m, r;
}D;

D ans;

void twopointer(int pivot,int mini,int maxi) {

	while (mini < maxi) {

		long long dis = vec[mini] + vec[maxi] + vec[pivot];

		if (res > abs(dis)) {
			res = abs(dis);
			ans = {pivot,mini,maxi};
		}

		if (dis == 0) {
			flag = 1;
			return;
		}

		if (dis < 0)
			mini++;
		else if (dis > 0)
			maxi--;

	}
	
}

int main() {

	cin >> n;

	for (int x = 0; x < n; x++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end());

	for (int x = 0; x <= n; x++) {
		twopointer(x, x + 1, n - 1);
		if (flag == 1)
			break;
	}

	cout << vec[ans.l] << ' ' <<vec[ans.m]<< ' '<< vec[ans.r];

	return 0;
}