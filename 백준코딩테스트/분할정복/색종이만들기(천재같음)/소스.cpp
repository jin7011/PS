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
  
		for (int x = r; x < r + m; x++) {// �־��� ������ ��� Ž���Ѵ�. ������ ������ ���� �������� �Ѿ. (�ݺ�Ż�� �� ���� �Լ�ȣ��)
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
			black++; // �־��� ��üũ�� ��� �������� �������� ��� ù��° ��Ʈ�� 1 �Ǵ� 0�̶�� ���� �ش�.
		else
			white++;
		return;
	}

	//��ü�� ���� ���� ������ �ִ� ���� �ϴ� 4���и����� ������ ����� �ݺ������Ѵ�

	calc(m / 2, r, c); //����
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