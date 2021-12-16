#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>

using namespace std;

int ans = 0;
bool chk;
int legoNum, width;

int main() {

	while (scanf("%d", &width) == 1) {

		cin >> legoNum;
		width *= pow(10, 7);

		vector<int> legos(legoNum);

		for (int i = 0; i < legoNum; i++) {
			cin >> legos[i];
		}

		sort(legos.begin(), legos.end());

		int mini = 0;
		int maxi = legoNum - 1;

		while (mini < maxi) {

			int sum = legos[mini] + legos[maxi];

			if (sum == width) {
				cout << "yes" << ' ' << legos[mini] << ' ' << legos[maxi];
				chk = 1;
				break;
			}

			if (sum > width)
				maxi--;
			else
				mini++;
		}
	}

	if(chk)
	cout << "danger";

	return 0;
}
