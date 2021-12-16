#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector <int> vec[100001];
int parent[100001];

void findP(int node) {

	for (int i = 0; i < vec[node].size(); i++) {

		int next = vec[node][i];
		if (parent[node] != next) {
			parent[node] = next;
			findP(next);
		}

	}
}

int main() {
	cin >> n;
	int o = n-1;

	while (o--) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);

	}

	findP(1);

	for (int x = 2; x <= n; x++)
		cout << parent[x] << ' ';

	return 0;
}