#include<iostream>
#include<deque>
#include <queue>
#include<string>
#include<functional>
#include <math.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <stack>

using namespace std;

int map[128][128];
int white_cnt = 0;
int blue_cnt = 0;

void color_paper(int size, int x, int y) {

	int flag = 0;

	if (size == 1) {   // 1�������� ���� ���� ��.
		if (map[x][y] == 1) {
			blue_cnt += 1;
		}
		else {
			white_cnt += 1;
		}
		return;
	}

	for (int i = x; i < x + size; i++) {
		if (flag == 1) {
			break;
		}
		for (int j = y; j < y + size; j++) {   //������ ������ �� flag++ Ż��
			if (map[x][y] != map[i][j]) {
				flag = 1;
				break;
			}
		}
	}

	if (flag == 0) {
		if (map[x][y] == 1) {
			blue_cnt += 1;
		}
		else {
			white_cnt += 1;
		}
		return;
	}

	color_paper(size / 2, x, y);
	color_paper(size / 2, x + size / 2, y);
	color_paper(size / 2, x, y + size / 2);
	color_paper(size / 2, x + size / 2, y + size / 2);

}

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	color_paper(n, 0, 0);

	cout << white_cnt << "\n" << blue_cnt;

	return 0;
}