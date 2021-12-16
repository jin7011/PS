#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long n;
long long m;
long long t;
long long res = 0;
vector <long long> vec;

int main() {

	cin >> n >> m; // �ɻ�� ���� , ��� ��

	for (int x = 0; x < n; x++)
	{
		cin >> t; // �� �ɻ�� �ɸ��� �ð�.
		vec.push_back(t);
	}

	long long mini;
	long long maxi;

	mini = 0;
	maxi = *max_element(vec.begin(), vec.end()) * m;

	while (mini <= maxi) {
		
		long long mid = (mini + maxi + 1) / 2; // �ɸ��� �ð�
		long long cnt = 0;
		cout << mini << ' ' << maxi << ' ' << mid << '\n';
		for (int x = 0; x < vec.size(); x++) {
			cnt += mid / vec[x]; // ���� �����
		}

		if (cnt >= m) {
			res = mid;
			maxi = mid - 1;
		}
		else {
			mini = mid + 1;
		}
	}

	cout << res;

	return 0;
}