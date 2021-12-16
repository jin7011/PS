#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <functional>

using namespace std;

vector <int> vec; // 휴게소위치
vector <int> num;
int cnt = 0;

int n;  // 현재휴게소 갯수
int m; // 추가되는 ㅎ게소 갯수
int l; // 고속도로 길이

// 휴게소를 더 지어서 휴게소간의 빈공간의 최대값의 최솟값을 출력
int binary() {
	int left; //빈공간의 최솟값
	int right; // 빈공간의 최댓값

	left = 1;
	right = l-1; // 간격이 최대인 것부터

	while (left <= right) {

		int mid = (left + right) / 2;
		cnt = 0;

		for (int x = 1; x < vec.size(); x++) {

			cnt += (vec[x]-vec[x-1]) / mid; // 공간이 허용하는만큼 휴게소 오지게 설치
			if ((vec[x] - vec[x - 1]) % mid == 0) // ex) 0 과 500사이에 250을 두개 지을수 있지만 그러면 (250,500)이 지어지고 그러면 500이 설치된 곳에 또 설치된거니까 --
				cnt--;

			//if (cnt > 0) cout << num[x] << ' ';

		}
		cout << left << ' ' << mid << ' ' << right <<' '<< cnt << '\n';
		if (cnt > m) //예상보다 많이 설치되었다면, 범위를 넓히자 (더 좁은 범위는 마찬가지로 더 많이 설치할테니 볼 필요x)
			left = mid + 1;
		else
			right = mid - 1;

	}

	return left;
}

int main() {
	// n+m < l
	cin >> n >> m >> l;

	int o = n;
	int a;

	vec.push_back(0);
	while (o--) {
		cin >> a;
		vec.push_back(a);
	}
	vec.push_back(l); // 고속도로 길이의 끝부분도 계산해주자

	sort(vec.begin(), vec.end()); // 일단 오름차순으로 정렬 (휴게소간의 간격을 차례로 보고나서 가장 큰 간격을 binary_search할 예정.

	//sort(num.begin(), num.end(),greater<int>());

	////////////////////////////////////////////////////////////////////////////////////////정리완료

	cout << binary();

	return 0;

}