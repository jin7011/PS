#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

int n, m;
int mini;
int maxi;
int res;
vector <int> vec;

int func(int v) { //v이상의 숫자가 몇 개 있는지 세는 함수

	int cnt = 0;

	for (int x = 0; x < vec.size(); x++) {
		if (vec[x] >= v)
			cnt += vec[x] / v;
	}

	return cnt;
}

int main() {

	cin >> n >> m;
	int len;
	for (int x = 0; x < m; x++) {
		cin >> len;
		vec.push_back(len);
	}

	sort(vec.begin(), vec.end());

	mini = 1;
	maxi = *max_element(vec.begin(), vec.end()); // 과자최대길이


	while (mini <= maxi) {

		int mid = (mini + maxi) / 2;
		int scnt = 0;

		scnt = func(mid); // 과자길이에 대해 줄 수 있는 사람 수

		if (scnt >= n) { // 줄 수 있는 사람수가 너무 많으면
			res = mid;
			mini = mid + 1; //과자 길이를 늘리자.(최대한 길게 주고 싶기때문에
			//적정인원에게 나눠주었따고 해도 좀 더 늘려서 다시 체크해보는 거임)
		}
		else {
			maxi = mid - 1;
		}

	}

	cout << res;

	return 0;
}