#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <stdlib.h>

using namespace std;

int n;
int k = 0;
priority_queue <int, vector<int>, less<int>> maxq;
priority_queue <int,vector<int>,greater<int>> minq;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int k = 0;
	
	cin >> k;
	
	maxq.push(k);    //�ִ����� top�� �߾Ӱ����� ���� ù��° ���ڸ� �޾Ƶ��δ�.
	cout << maxq.top()<<'\n';
	n--;

	while (n--) {

		cin >> k;
		if (maxq.top() < k) {   //�߾Ӱ����� ū ���� �氪���� �ѱ�.
			minq.push(k);
		}
		else {
			maxq.push(k);
		}
		if (maxq.size() < minq.size()) {    // �߾Ӱ����� �氪�� ũ�Ⱑ �� ũ�ٸ� �߾Ӱ����� �ű�� pop
			maxq.push(minq.top());
			minq.pop();
		}
		else if (maxq.size() - 1 > minq.size()) { //�߾Ӱ��� ũ�� -1 ���� �氪�� �� ũ�ٸ� �߾Ӱ��� �氪���� ������ pop
			minq.push(maxq.top());
			maxq.pop();
		}

		cout << maxq.top() << '\n';   // ������ ��ġ���� maxq�� top �� �߾Ӱ��� �ȴ�. 
	}
	return 0;
}