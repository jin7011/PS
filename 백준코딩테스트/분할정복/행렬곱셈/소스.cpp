#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;

int a[101][101];
int b[101][101];
int c[101][101];

int n, m,k;
// c[x][y] = a[x][0] * b[0][y] + a[x][1]*b[1][y]


// c[x][y] += a[x][i]*b[i][y] + a[x][i]*b[i][y]
int func(int m,int x,int y) {
	
	return a[x][m] * b[m][y];

}

void func2(int m) {

	int r = 0;

	for(int x=0;x<n;x++)
		for (int y = 0; y < k; y++) {
			while (r != m) {
				c[x][y] += func(r, x, y);
				r++;
			}
			r = 0;
		}

}

int main() {

	cin >> n >> m;

	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
			cin >> a[x][y];

	cin >> m >> k;

	for (int x = 0; x < m; x++)
		for (int y = 0; y < k; y++)
		cin >>	b[x][y];

	func2(m);

	for (int x = 0; x < n; x++) {
		if(x!=0)cout << '\n';
		for (int y = 0; y < k; y++)
			cout << c[x][y] <<' '; 
	}

	return 0;
}