#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int t, n;
bool visited[100001];
bool circled[100001];
int cnt;
int res;

vector <int> vec[100001];
queue <int> visi;
queue <int> unionf;
queue <int> c;
stack <pair<int,int>> que;
//vector <int> res;

void unionfind() {

	while (!unionf.empty()) {
		int qf = unionf.front();
		circled[qf] = 1;
		c.push(qf);
		cnt++;
		unionf.pop();
	}

}

void getcircle(int v) {

	bool flag = 0;

	que.push({ v,v });
	visi.push(v);
	visited[v] = 1;

	while (!que.empty()) {

		int qf = que.top().first;
		int from = que.top().second;

		que.pop();

		for (int x = 0; x < vec[qf].size(); x++) {

			int next = vec[qf][x];

			if (next == from) {
				unionf.push(next);
				unionfind();
				return;
			}

			if (!visited[next]) {
				flag = 1;
				visited[next] = 1;
				visi.push(next);
				unionf.push(next);
				que.push({ next,from });
			}
		}
	}

	while (!unionf.empty())
		unionf.pop();

}

void set() {

	while (!visi.empty()) {
		visited[visi.front()] = 0;
		visi.pop();
	}

	while (!que.empty())
		que.pop();

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--) {

		cin >> n;

		for (int q = 1; q <= n; q++)
		{
			int a;
			cin >> a;
			vec[q].push_back(a);
		}

		for (int x = 1; x <= n; x++) {
			if (!circled[x]) {
				getcircle(x);
				set();
			}
		}

		res = n - cnt;

		cout << res << '\n';

		cnt = 0;

		for(int q = 1; q <= n; q++)
		vec[q].clear();
		while (!c.empty()) {
			circled[c.front()] = 0;
			c.pop();
		}
	}

	return 0;
}