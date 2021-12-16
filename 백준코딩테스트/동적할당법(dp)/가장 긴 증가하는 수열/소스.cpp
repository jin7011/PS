#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int n;
int a[1000001];
int dp[1000001];
int cnt = 0;


int main() {

	cin >> n;

	for (int x = 0; x < n; x++)
		cin >> a[x];

	dp[0] = 1; // �ڱ������̹Ƿ� �׻� 1�� �����ϴµ� ù��° �������� ���������� ����� �����Ƿ� 1�� ����

	for (int x = 1; x < n; x++) {
		dp[x] = 1; //dp[����] = 1 (�ڱ�����) ���� �����ؼ� ���������� ���ڿ� dp(�����)�� ���غ���.
		for (int y = 0; y < x; y++) {
			if (a[x] > a[y]) {
				dp[x] = max(dp[y] + 1, dp[x]); // ����(j)���� ���� ���� �ִٸ� �� ���� ���� ������ ���� ������ ���� ���� ���� ��ϵ� dp�� �ִ��� Ȯ���ϰ� 
												// �� dp+1�� ū�� ���� ������(i)�� dp�� ū�� Ȯ���ؼ� ���� ����Ѵ�.
			}
		}
	}
	
	cout << *max_element(dp, dp + n);

	return 0;
}