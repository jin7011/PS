#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define IFT 10000000;

using namespace std;

vector <int> vec[101];

long long d[101][101];
int a, b,c;
int n,m;

void show() {

	for (int y = 1; y <= n; y++) {
		if(y!=1)
		cout << '\n';
		for (int x = 1; x <= n; x++) {
			cout << d[y][x] << ' ';
		}
	}
}

void floyd() {

	for (int k = 1; k <= n; k++)
		for (int start = 1; start <= n; start++)
			for (int end = 1; end <= n; end++)
			{
				if (start == end) continue;

				if (d[start][k] != 0 && d[k][end] != 0) { //경유해서 가는 길이 있을 때
					if (d[start][end] != 0) { //경유지와 직진이 다 있을때

						if (d[start][k] + d[k][end] < d[start][end])
							d[start][end] = d[start][k] + d[k][end];
					}
					else if(d[start][end] == 0) //직진이 없고 경유지만 있을 때.
						d[start][end] = d[start][k] + d[k][end];
				}
			}
}

int main() {

	cin >> n>> m ; // num of city and bus(간선)

	//for (int y = 1; y <= n; y++) 
	//	for (int x = 1; x <= n; x++) {
	//		if (x == y)
	//			d[y][x] == 0;
	//		else
	//		d[y][x] = IFT;
	//	}
	

	while (m--) {

		cin >> a >> b >> c; 

		if (d[a][b] != 0 && d[a][b] > c) // 이전자료보다 작은 값만 저장.
			d[a][b] = c;
		else if (d[a][b] == 0)
			d[a][b] = c;

	}

	floyd();

	show();

	return 0;
}