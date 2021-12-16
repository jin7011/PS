#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

int vec[100001];
int LIC[10001];
int LDC[10001];
int dp[10001];

int i = 0;
int n;
int k=0;
int MAXINDEX[10001];


void func() {

	//LIC
	LIC[0] = 1;
	LDC[n-1] = 1;
	for (int x = 1; x < n; x++) {
		LIC[x] = 1;
		for (int y = 0; y < n; y++) {
			if (vec[x] > vec[y])
				LIC[x] = max(LIC[x], LIC[y] + 1);
		}
	}

	for (int x = n -2; x >= 0; x--) {
		LDC[x] = 1;
		for (int y = x+1; y < n; y++) {
			if (vec[x] > vec[y]) {
				LDC[x] = max(LDC[x], LDC[y] + 1);
			}
		}
	}

}

int main() {

	cin >> n;

	for (int x = 0; x < n; x++) {
		cin >> vec[x];
	}

	func();

	for (int x = 0; x < n; x++) {
		dp[x] = LDC[x] + LIC[x];
	}

	cout << *max_element(dp, dp + n)-1;

	return 0;
}