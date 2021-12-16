#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int v;
int m;
int n;
bool* c;
vector <vector<int>> vec;
queue <int> que;
deque <int> deq;
stack <int> stk;

bool des(int a, int b) {
	return a>b;
}

void dfs(int x)
{
	if (c[x] == 1) return;
	else {
		c[x] = true;
		cout << x << ' ';
		for (int i = 0; i < vec[x].size(); i++) {
			dfs(vec[x][i]);
		}
	}
}

void dfs_stack(int x) {

}

void bfs(int x) {

		que.push(x);// 처음 들어온 숫자를 push하고 나머진 뒤에서 
		c[x] = true;

		while (!que.empty()) {

			int qf = que.front();
			cout << qf << ' ';
			que.pop();

			for (int q = 0; q < vec[qf].size(); q++) {
				if (c[ vec[qf][q] ] != 1) {
					que.push(vec[qf][q]);
					c[ vec[qf][q] ] = true;

				}
			}
		}
}

int main() {

	cin >> n >> m >> v;
	c = new bool[n+1];
	vec.resize(n+1);

	for(int q=0; q<m;q++) {

		int a=0;
		int b=0;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);

	}

	/*for (int q = 0; q < n; q++) {
		sort(vec.begin(), vec.end(), des);
	}*/ // 어떤입력이 들어올지 모르기때문에 내림차순으로 정리해준다.
	
	for (int q = 0; q < n; q++)
		sort(vec[q].begin(), vec[q].end());

	dfs(v);
	cout << '\n';

	for (int q = 0; q <= n; q++)
		c[q] = 0;   //방문초기화
	
	bfs(v);

	//vec[1].push_bakc(2);
	//vec[2].pushback(1);
	//vec[2]
	//
	//

	return 0;
}