#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

queue <int> q;

int n = 0;
int a[5000001];
int i = 0;

int main() {

	cin >> n;

	for (int x = 1; x <= n; x++) 
		q.push(x);
	

	while (q.size() != 1) {

		if (q.size() != 1) 
			q.pop();
		if (q.size() != 1)
			q.push(q.front());
		if (q.size() != 1)
			q.pop();
		
	}

	cout << q.front();
	return 0;
}