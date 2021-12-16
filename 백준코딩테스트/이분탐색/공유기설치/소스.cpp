#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <math.h>

using namespace std;

int n = 0; // >=2   집의 수
int c = 0; // >=2 <=n 공유기의 수
int d = 0; // 거리
int base = 0; // 최초 설치기준점.

int a[2000001];
int b[200001];
int res = 0;

int distance(int a,int b) {

	return abs(a - b);

}

int cnt = 0;

void func() {
	int left = 1; //최소거리
	int right = a[n-1] - a[0]; // 최대거리
	
	while (left <= right) {

		int middle = (left + right) / 2;
		int base = a[0]; // 가장 첫번째 집이 처음 기준. 반복할 때마다 계속
		cnt = 1;

		for (int x = 1; x < n; x++)
		{
			if (a[x] - base >= middle) { //설치할 집과 이전설치한 집의 거리가 >=middle일때, 설치한다.
				cnt++;
				base = a[x]; // 거리8 에 설치했다면 base는 8이고 8보다 거리가 먼 곳에만 설치가 가능하다. ex) 9
			}
		}
		 if (cnt >= c) { //제공된 공유기의 수보다 설치한 공유기수 이상이면 middle을 결과값으로 저장하고 범위를 늘린다.
			 res = middle;
			left = middle + 1;  //최소거리를 이전의 절반이상으로 늘린다.

			//어찌됬건 적게 설치하는게 목표가 아니라 최대거리가 목표이므로 늘리면서 확인한다.

		}
		 else {
			right = middle - 1; //설치한 수가 적으면 범위를 좁힌다. (좁혀앉아야 많이 앉을 수 있는 것처럼) 따라서 최대거리를 이전의 절반 이하로 좁힌다.

		}
	}
	cout << res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> c;
	
	for (int x = 0; x < n; x++) {
		cin >> a[x];
	}
	
	sort(a, a + n);
	
	func();

	return 0;

}