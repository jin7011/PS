#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>

#define no 999999999

using namespace std;

int n;
int h;

vector <int> up;
vector<int> bottom;
vector <int> res;
priority_queue<int,vector<int>,greater<int> > pq;

int cnt[1000001];

bool uprange(int h,int mid) {
	return h <= up[mid];
}

bool bottomrange(int h, int mid) {
	return h <= bottom[mid];
}

int kickbottom(int start, int end, int h) {

	int left = start;
	int right = end;
	int val = no;

	while (left <= right) {

		int mid = (left + right) / 2;

		if (bottomrange(h, mid)) {

			if (val >= mid) {
				val = mid; // 해당 높이에서 up[mid]가 부딪혔다면 일단 저장하고 다음 중간을 탐색.
				right = mid - 1; //  up[mid]에서 닿았다면 당연히 그보다 높은기둥은 전부 다 닿았을 것이므로 더 낮은 기둥을 탐색하기 위해 범위를 좁힌다 
			}
		}
		else {
			left = mid + 1; // 반대로 up[mid]에서 닿지않았다면 좀 더 높은 기둥을 탐색해본다.
		}

	}
	if (val == no)
		return 0;
	else
		return (n/2) - val;
}

int kickup(int start, int end, int h) {
	
	int left = start;
	int right = end;
	int val = no;

	while (left <= right) {

		int mid = (left + right) / 2;

		if (uprange(h, mid)) {

			if (val >= mid) {//이전에 부셧던 벽의 높이를 저장~
				val = mid;
				right = mid - 1;
			}
		}
		else {
			left = mid + 1;
		}
		
	}
	if (val == no)
		return 0;
	else
		return (n / 2) - val;
}

int main() {

	int a, b;
	cin >> n >> h;
	int o = n / 2;

	while (o--) {
		cin >> a >> b;
		up.push_back(b);
		bottom.push_back(a); // 바닥부터 자라나기로 했음 그래서 바닥먼저.
	}

	sort(up.begin(), up.end());
	sort(bottom.begin(), bottom.end());//작은 기둥 ~ 큰 기둥 (바닥에 자라난 기둥크기)

	for (int x = 1; x <= h; x++) {
		int resalt = kickbottom(0, (n / 2) - 1, x) + kickup(0, (n / 2) - 1, (h+1) - x);
		pq.push(resalt);
		cnt[resalt]++;
	}

	cout <<pq.top() <<' '<< cnt[pq.top()];

	return 0;
}