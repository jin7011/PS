#include <iostream>
using namespace std;
long long cash[100] = { 1,1,1,2,2,0, };
//p(n-3) + p(n-2) = p(n)    ( n >= 3 )

long long func(int n) {

	for (int x = 3; x < n; x++) {

		cash[x] = cash[x - 3] + cash[x - 2]; // 없으면 저장
	}

	return cash[n-1];

}

int main() {

	int T = 0; cin >> T;
	int* n; n = new int[T];

	for (int x = 0; x < T; x++) {
		cin >> n[x]; //T만큼 n 받고 반복
	}
	
	for (int x = 0; x < T; x++)
		cout << func(n[x]) << '\n';



	return 0;

}