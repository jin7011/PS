#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int n, k,w,v;
int W[101];
int V[100001]; 
int res = 0;
int dp[101][100001];

void func() { //    ��������� ���԰� ���� �־������� ���� ��ġ�� ��ư� �� �ֱ⋚���� dp�� �������� �ִ밪�� �ȴ�.

	for (int i = 1; i <= n; i++) {
		for (int w = 1; w <= k; w++) {

			dp[i][w] = dp[i - 1][w];   // �̹� ������ ���� �ʴ´ٰ� ���� �����ϰ�   (�߿�)

			if (w - W[i] >= 0) {  //���Ը� ���� �̹������� ���� �� �ִ� �������� �� �־�� 
				int n1 = dp[i - 1][w - W[i]] + V[i]; // ������ �ִ� ������ ���λ��� �̹������� �־��� ��, ���� ���Կ��� �����Ѹ��� �ٸ� ������ �� ���� ��ġ
				int n2 = dp[i - 1][w]; // �ٽ� �����غ��� �̹� ������ �ȳִ°� ���ڴ� ������ ��ġ

				dp[i][w] = max(n1,n2); // �� ū���� ���Ͽ� �����Ѱ� �־��� ���Կ��� �ִ밡ġ��

			}
			else {
				continue;

			}
		}
	}


}

int main() {

	cin >> n >> k; // ���� 4 , ���� 7

	for (int x = 1; x <= n; x++) {
		cin >> W[x] >> V[x];
	}

	func();

	for (int x = 1; x <= n; x++) {
		cout << '\n';
		for (int y = 0; y <= k; y++)
			cout << dp[x][y] << ' ';
	}
	cout <<'\n';

	cout << dp[n][k];

	return 0;
}