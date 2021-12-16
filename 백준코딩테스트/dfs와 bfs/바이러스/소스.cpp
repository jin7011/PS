#include <iostream>
#include <functional>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

priority_queue <int> pq;
vector <vector<int>> vec;
queue <int> que;

//int map[26][26];
//bool visited[26][26];

bool* c;
int n;
int sum = 0;
int m;
int a, b;
//int danji = 0;
int housecnt = 0;
int qf;

void bfs(int v) {
	
	que.push(v); // start
	c[v] = true;
	
	while (!que.empty()) {

		qf = que.front();

		if (qf != 1) {
			sum++;
		}

		que.pop();

		for (int x = 0; x < vec[qf].size(); x++) {
			if (!c[vec[qf][x]]) {
				que.push(vec[qf][x]);
				c[vec[qf][x]] = true;
			}
		}

	}
	
}

int main() {

	cin >> n >> m; //num of com
	vec.resize(n + 1);
	c = new bool[n + 1];

	while (m--) {

		cin >> a >> b;

		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for(int x=1;x<=n;x++)
		sort(vec[x].begin(), vec[x].end());

	for (int x = 1; x <= n; x++)
		c[x] = 0;

	bfs(1);

	cout << sum;

	return 0;
}