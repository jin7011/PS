#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <math.h>

using namespace std;

int n = 0; // >=2   ���� ��
int c = 0; // >=2 <=n �������� ��
int d = 0; // �Ÿ�
int base = 0; // ���� ��ġ������.

int a[2000001];
int b[200001];
int res = 0;

int distance(int a,int b) {

	return abs(a - b);

}

int cnt = 0;

void func() {
	int left = 1; //�ּҰŸ�
	int right = a[n-1] - a[0]; // �ִ�Ÿ�
	
	while (left <= right) {

		int middle = (left + right) / 2;
		int base = a[0]; // ���� ù��° ���� ó�� ����. �ݺ��� ������ ���
		cnt = 1;

		for (int x = 1; x < n; x++)
		{
			if (a[x] - base >= middle) { //��ġ�� ���� ������ġ�� ���� �Ÿ��� >=middle�϶�, ��ġ�Ѵ�.
				cnt++;
				base = a[x]; // �Ÿ�8 �� ��ġ�ߴٸ� base�� 8�̰� 8���� �Ÿ��� �� ������ ��ġ�� �����ϴ�. ex) 9
			}
		}
		 if (cnt >= c) { //������ �������� ������ ��ġ�� ������� �̻��̸� middle�� ��������� �����ϰ� ������ �ø���.
			 res = middle;
			left = middle + 1;  //�ּҰŸ��� ������ �����̻����� �ø���.

			//������ ���� ��ġ�ϴ°� ��ǥ�� �ƴ϶� �ִ�Ÿ��� ��ǥ�̹Ƿ� �ø��鼭 Ȯ���Ѵ�.

		}
		 else {
			right = middle - 1; //��ġ�� ���� ������ ������ ������. (�����ɾƾ� ���� ���� �� �ִ� ��ó��) ���� �ִ�Ÿ��� ������ ���� ���Ϸ� ������.

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