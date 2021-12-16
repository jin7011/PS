#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct D {
	int start;
	int end;
	int val;
}D;

int n, d;
int dp[10001];
D go[10001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> d;
	
	for (int x = 0; x < n; x++) 
		cin >> go[x].start >> go[x].end >> go[x].val;

	sort(go, go + n, [](D& q, D& w) -> bool {return q.start < w.start; });

	int now = 0;
	int idx = 0;

	while (now != d) {

		if (go[idx].start == now) {

			if (go[idx].end <= d) {
				if (dp[go[idx].end] != 0) {// �������� �̹� ��ϵǾ� �ִٸ�.
					dp[go[idx].end] = min(dp[go[idx].end], dp[now] + go[idx].val); //dp �� ����. -> ���߿� ������ �� ���� ^-^	
				}
				else // ÷���� ������
					dp[go[idx].end] = go[idx].val + dp[now];
			}
			idx++;
		}
		else {
		
			if (dp[now+1] != 0) { // �������� �ִٸ�
				dp[now+1] = min(dp[now]+1, dp[now+1]);
			}
			else
				dp[now+1] = dp[now]+1;

			now++; // �� ���� ������ (������ ������ �Ѱ�������) Ȯ���ϰ� ������

		}

	}

	cout << dp[d];

	return 0;
}