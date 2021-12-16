#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {
	
	int n;
	int k = 0;
	cin >> n;
	int p = n;

	for (int x =0 ; x <= (2*n-1)/2 ; x++) {
		k = x;
		if(x>0)
		while (k--) {
			cout << ' ';
		}
		for (int y =1 ; y <= 2*p-1 ; y++) {
			cout << '*';
		}
		cout << '\n';
		p--;
	}
	p++;
	p++;
	for (int x = (2 * n - 1) / 2-1; x >= 0; x--) {
		k = x;
		if (x > 0)
			while (k--) {
				cout << ' ';
			}
		for (int y = 1; y <= 2 * p - 1; y++) {
			cout << '*';
		}
		cout << '\n';
		p++;
	}
	


	return 0;
}