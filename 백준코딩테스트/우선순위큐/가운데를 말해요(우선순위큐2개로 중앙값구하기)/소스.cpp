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
	
	maxq.push(k);    //최대힙의 top를 중앙값으로 놓고 첫번째 인자를 받아들인다.
	cout << maxq.top()<<'\n';
	n--;

	while (n--) {

		cin >> k;
		if (maxq.top() < k) {   //중앙값보다 큰 수는 헐값으로 넘김.
			minq.push(k);
		}
		else {
			maxq.push(k);
		}
		if (maxq.size() < minq.size()) {    // 중앙값보다 헐값의 크기가 더 크다면 중앙값으로 옮기고 pop
			maxq.push(minq.top());
			minq.pop();
		}
		else if (maxq.size() - 1 > minq.size()) { //중앙값의 크기 -1 보다 헐값이 더 크다면 중앙값을 헐값으로 버리고 pop
			minq.push(maxq.top());
			maxq.pop();
		}

		cout << maxq.top() << '\n';   // 절차를 마치고나면 maxq의 top 는 중앙값이 된다. 
	}
	return 0;
}