#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[100001];
int res[10001];
int visited[1000001];
int k;

int find(int v) {
	for (int x = 0; x < n; x++)
		if (a[x] == v)
			return x;
}

void boolmaker(int index) { //�ε����� �޴´�
	for (int x = index+1; x < n; x++) {
		//if (x == index) continue; //���� �ε�������
		if (a[x] == a[index]) { //�ٸ� �ε����ε� ���� ������ 0ó��
			visited[x] = 1;
		}
	}
}

void func(int cnt, int start,int index) {
	if (cnt == m) {
		for (int x = 0; x < cnt; x++) {
			cout << res[x] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int x = start; x < n; x++) {
		if (!visited[x]) {
			res[cnt] = a[x];
			func(cnt + 1, find(res[cnt]), x);
		}

	}

}


int main() {

	cin >> n >> m;

	for (int x = 0; x < n; x++)
		cin >> a[x];

	sort(a, a + n);

	for (int x = 0; x < n; x++) {
		if(!visited[x])
		boolmaker(x);
	}

	func(0,0,0);

	return 0;
}