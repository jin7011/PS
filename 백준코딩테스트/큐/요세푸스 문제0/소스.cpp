#include<iostream>
#include<queue>

using namespace std;

int n = 0;
int k = 0;
int a[1001];
int i = 0;
int b[1001];

queue <int> que;

int main() {
	int cnt = 0;
	int x = 1;
	cin >> n>> k;

	for (int x = 1; x <= n; x++)
		b[x] = x;


	while (i != n) {
		
		while(cnt!=k) { //k번 push했을 때 front옮기고 pop할 예정.

			if (x > n) {
				x = 1;
			}

			if (b[x] != -1) {
				que.push(b[x]);
				x++;
				cnt++;
			}
			else x++;

		}

		a[i] = que.back();
		i++;

		b[que.back()] = -1;
		cnt = 0;
	}

	cout << "<";
	cout << a[0];
	for (int x = 1; x < n; x++)
		cout << ", "<<a[x];
	cout << ">";

	return 0;
}