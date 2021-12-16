#include <iostream>
#define SIZE 1000000000;
using namespace std;

long long arr[101][10] = {};
int n;

int main() {

	cin >> n; // ÀÚ¸®¼ö

	//arr[1][0] = 0;

	for (int i = 1; i < 10; i++) {
		arr[1][i] = 1;
	}

	for (int x = 2; x <= n; x++)
		for (int y = 0; y <= 9; y++) {
			if (y == 0)
				arr[x][y] = arr[x - 1][1];
			else if (y == 9)
				arr[x][y] = arr[x - 1][8];
			else
				arr[x][y] = (arr[x - 1][y - 1] + arr[x - 1][y + 1]) % SIZE;
		}

		long long sum = 0;
		for (int num = 0; num <= 9; num++) {
			sum += arr[n][num];
			sum = sum % SIZE;
		}
		cout << sum % SIZE;	
	
}
