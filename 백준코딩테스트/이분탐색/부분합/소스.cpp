#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, s;
vector <int> vec;
int sum,mini,maxi,res;

bool func(int len,int cutline) {

	int sum = 0;

	for (int x = 0; x < len; x++)
		sum = sum + vec[x];

	if (sum >= cutline)
		return 1;

	for (int x = len; x < vec.size(); x++) {
		sum = sum - vec[x - len] + vec[x];
		if (sum >= cutline)
			return 1;
	}

	return 0;
}

int main() {

	cin >> n >> s;

	for (int x = 0; x < n; x++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
		sum += a;
	}

	mini = 1;
	maxi = n;

	while (mini <= maxi) {

		bool chk = 0;
		int mid = (mini + maxi) / 2; // s를 넘는 연속된 부분수열의 갯수

		if (func(mid,s))
			chk = 1;

		if (chk) {
			res = mid;
			maxi = mid - 1;
		}
		else
		{
			mini = mid + 1;
		}

	}

	cout << res;

	return 0;
}