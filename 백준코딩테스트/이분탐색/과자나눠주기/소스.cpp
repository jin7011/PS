#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

int n, m;
int mini;
int maxi;
int res;
vector <int> vec;

int func(int v) { //v�̻��� ���ڰ� �� �� �ִ��� ���� �Լ�

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
	maxi = *max_element(vec.begin(), vec.end()); // �����ִ����


	while (mini <= maxi) {

		int mid = (mini + maxi) / 2;
		int scnt = 0;

		scnt = func(mid); // ���ڱ��̿� ���� �� �� �ִ� ��� ��

		if (scnt >= n) { // �� �� �ִ� ������� �ʹ� ������
			res = mid;
			mini = mid + 1; //���� ���̸� �ø���.(�ִ��� ��� �ְ� �ͱ⶧����
			//�����ο����� �����־����� �ص� �� �� �÷��� �ٽ� üũ�غ��� ����)
		}
		else {
			maxi = mid - 1;
		}

	}

	cout << res;

	return 0;
}