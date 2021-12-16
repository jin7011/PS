#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	int count, s, i, j;
	int size, sX, sY, eX, eY;
	cin >> count;
	int* result = new int[count];

	int moveX[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int moveY[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

	for (s = 0; s < count; s++) {

		scanf("%d %d %d %d %d", &size, &sX, &sY, &eX, &eY);

		int map_arr[size][size];

		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++) {
				map_arr[i][j] = -1;
			}
		}

		queue< pair<int, int> > Q;
		Q.push(make_pair(sX, sY));
		map_arr[sX][sY] = 0;

		while (!Q.empty()) {
			int currX = Q.front().first;
			int currY = Q.front().second;
			Q.pop();

			if (currX == eX && currY == eY) break;

			for (i = 0; i < 8; i++) {
				int nextX = currX + moveX[i];
				int nextY = currY + moveY[i];

				if (nextX >= 0 && nextY >= 0 && nextX < size && nextY < size) {
					if (map_arr[nextX][nextY] == -1) {
						Q.push(make_pair(nextX, nextY));
						map_arr[nextX][nextY] = map_arr[currX][currY] + 1;
					}
				}
			}
		}

		result[s] = map_arr[eX][eY];
	}

	for (int x = 0; x < count; x++) {
		cout << result[x] << endl;
	}

	return 0;
}