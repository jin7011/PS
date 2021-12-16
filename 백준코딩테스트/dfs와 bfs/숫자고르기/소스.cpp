#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int n;
int visited[101];
//int res;
int ind;

vector <int> vec[101];
set <int> res;
stack <int> stk;

void setvisited() {

	for (int x = 1; x <= n; x++)
		visited[x] = 0;
}

void dfs(int start) {

	stk.push(start);
	visited[start] = 1;

	while (!stk.empty()) {

		int node = stk.top();

		stk.pop();

		for (int q = 0; q < vec[node].size(); q++) {
			int next = vec[node][q];

			if (next == start) { // 자신으로 되돌아온 경우 저장후 break;
				res.insert(start);

				while (!stk.empty())
					stk.pop();
				break;
			}

			if (!visited[next]) {
				stk.push(next);
				visited[next] = 1;
			}
		}

	}

}


int main() {

	cin >> n;

	for (int x = 1; x <= n; x++)
	{
		int a;
		cin >> a;
		vec[x].push_back(a);
	}

	//visited[1] = 1;
	for (int x = 1; x <= n; x++) {
		dfs(x);
		setvisited();
	}

//	set<int>::iterator iter;

	cout << res.size()<<'\n';
	for (auto x = res.begin(); x !=res.end(); x++) {
		cout << *x<< '\n';
	}

	return 0;
}