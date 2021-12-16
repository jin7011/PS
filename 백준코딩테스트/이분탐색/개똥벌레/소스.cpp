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
				val = mid; // �ش� ���̿��� up[mid]�� �ε����ٸ� �ϴ� �����ϰ� ���� �߰��� Ž��.
				right = mid - 1; //  up[mid]���� ��Ҵٸ� �翬�� �׺��� ��������� ���� �� ����� ���̹Ƿ� �� ���� ����� Ž���ϱ� ���� ������ ������ 
			}
		}
		else {
			left = mid + 1; // �ݴ�� up[mid]���� �����ʾҴٸ� �� �� ���� ����� Ž���غ���.
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

			if (val >= mid) {//������ �μ˴� ���� ���̸� ����~
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
		bottom.push_back(a); // �ٴں��� �ڶ󳪱�� ���� �׷��� �ٴڸ���.
	}

	sort(up.begin(), up.end());
	sort(bottom.begin(), bottom.end());//���� ��� ~ ū ��� (�ٴڿ� �ڶ� ���ũ��)

	for (int x = 1; x <= h; x++) {
		int resalt = kickbottom(0, (n / 2) - 1, x) + kickup(0, (n / 2) - 1, (h+1) - x);
		pq.push(resalt);
		cnt[resalt]++;
	}

	cout <<pq.top() <<' '<< cnt[pq.top()];

	return 0;
}