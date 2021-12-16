#include <algorithm>
#include <stdio.h>
#include <iostream>

using namespace std;

int map[128][128] = { -1 };

int n = 0;
int white = 0;
int black = 0;

void calc(int m, int r, int c) {


	if (m == 1) {
		if (map[r][c] == 1) black++;
		else white++;
		return;
	}

	int flag = 0;
  
		for (int x = r; x < r + m; x++) {// 주어진 구간을 모두 탐색한다. 문제가 생길경우 다음 구간으로 넘어감. (반복탈출 후 다음 함수호출)
			if (flag == 1)
				break;

			for (int y = c; y < c + m; y++) {
				if (map[r][c] != map[x][y]) {
					flag = 1;
					break;
				}
			}
		}

	if (flag == 0) {
		if (map[r][c] == 1) 
			black++; // 주어진 전체크기 모두 문제없이 지나쳤을 경우 첫번째 루트가 1 또는 0이라면 값을 준다.
		else
			white++;
		return;
	}

	//전체를 훑은 다음 문제가 있던 없던 일단 4개분면으로 구간을 나누어서 반복실행한다

	calc(m / 2, r, c); //기준
	calc(m / 2, r + m / 2, c);
	calc(m / 2, r, c + m / 2);
	calc(m / 2, r + m / 2, c + m / 2);

}

int main() {

	cin >> n;

	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			cin >> map[x][y];

	calc(n, 0, 0);

	cout << white << '\n' << black;

	return 0;
}