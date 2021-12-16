#include<iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <functional>
#include <queue>

using namespace std;

int n, m,cnt,a;
bool arr[10];
int ans;

void go(int val, int cnt) {

	if (val) ans = min(ans, abs(val - n) + cnt); // val != 0 �϶� (���� ans)�� ( (����ä�� - ��ǥä��) +�� �������ϴ� ��ư �� ) �ּ�
	if (val > n) return;

	for (int i = val == 0; i < 10; i++) {//ó�� ���� ��ư(val)�� 0 �̶�� i�� 1���� ������ �� �ִ� ����޽�ų**
		if (arr[i] != 1) 
			go(val * 10 + i, cnt + 1);// ���峭 ��ư�� �����ϰ� ������ ��ư�� ���� ��������.
	}
}

int main() {
	cin >> n >> m;

	for (int x = 0; x < m; x++)
	{
		cin >> a;
		arr[a] = 1;
	}
	
	ans = abs(n - 100); // abs(��ǥä�� - ����ä��) => +,- ��ư�������ϴ� Ƚ��
	if(arr[0] == 0) // 0 ��ư�� ������� ���
		ans = min(ans, n+1); 

	go(0, 0);

	cout << ans;
	
	return 0;
}