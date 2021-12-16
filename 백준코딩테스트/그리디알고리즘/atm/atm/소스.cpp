#include <iostream>
#include <algorithm>

using namespace std;

int p[2000];
int n;
int res = 0;
int sum = 0;

int Compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

long long func(int n) {

	qsort(p, n + 1, sizeof(int), Compare);

	for (int x = 1; x <= n; x++) {

		sum += p[x];
		res += sum;

	}

	return res;
}

int main() {

	cin >> n;

	for (int x = 1; x <= n; x++) {
		cin >> p[x];
	}

	cout << func(n);

	return 0;
}