#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <functional>

using namespace std;

vector <int> vec; // �ްԼ���ġ
vector <int> num;
int cnt = 0;

int n;  // �����ްԼ� ����
int m; // �߰��Ǵ� ���Լ� ����
int l; // ��ӵ��� ����

// �ްԼҸ� �� ��� �ްԼҰ��� ������� �ִ밪�� �ּڰ��� ���
int binary() {
	int left; //������� �ּڰ�
	int right; // ������� �ִ�

	left = 1;
	right = l-1; // ������ �ִ��� �ͺ���

	while (left <= right) {

		int mid = (left + right) / 2;
		cnt = 0;

		for (int x = 1; x < vec.size(); x++) {

			cnt += (vec[x]-vec[x-1]) / mid; // ������ ����ϴ¸�ŭ �ްԼ� ������ ��ġ
			if ((vec[x] - vec[x - 1]) % mid == 0) // ex) 0 �� 500���̿� 250�� �ΰ� ������ ������ �׷��� (250,500)�� �������� �׷��� 500�� ��ġ�� ���� �� ��ġ�ȰŴϱ� --
				cnt--;

			//if (cnt > 0) cout << num[x] << ' ';

		}
		cout << left << ' ' << mid << ' ' << right <<' '<< cnt << '\n';
		if (cnt > m) //���󺸴� ���� ��ġ�Ǿ��ٸ�, ������ ������ (�� ���� ������ ���������� �� ���� ��ġ���״� �� �ʿ�x)
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
	vec.push_back(l); // ��ӵ��� ������ ���κе� ���������

	sort(vec.begin(), vec.end()); // �ϴ� ������������ ���� (�ްԼҰ��� ������ ���ʷ� ������ ���� ū ������ binary_search�� ����.

	//sort(num.begin(), num.end(),greater<int>());

	////////////////////////////////////////////////////////////////////////////////////////�����Ϸ�

	cout << binary();

	return 0;

}