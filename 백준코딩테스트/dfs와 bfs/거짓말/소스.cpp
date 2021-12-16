#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

int n, m,trueN,res,partyperson;
int truenum[50];

vector < vector<int> > vec;

bool find(vector <int> v) {

	for (int x = 0; x < v.size(); x++) {
		bool flag = 0;
		for (int q = 0; q < trueN; q++) {
			if (v[x] == truenum[q]) {
				flag = 1;
				break;
			}
		}
		if (!flag)
			res++;
	}

}

void func() {

	

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	cin >> trueN;

	for (int x = 0; x < trueN; x++) {
		cin >> truenum[x];
	}

	int a;

	for (int x = 0; x < m; x++) {
		cin >> partyperson;

		for (int x = 0; x < partyperson; x++) {
			cin >> a;
			vec[x].push_back(a);
		}
	}

	func();

	cout << res;

	return 0;
}