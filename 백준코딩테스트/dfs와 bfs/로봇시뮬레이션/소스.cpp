#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

typedef struct R {
	int ry;
	int rx;
	int d;
}R;

vector <R> r;
int h,w,n, m; // ��ũ�� ,�κ����� , ��ɼ�
int go[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int map[101][101]; 

queue <pair<pair<int, int>, char> > que; // �κ��� ��ǥ ����
deque <pair<pair<int, char>, int>> command; // ����ϴ� �κ���ȣ,���,Ƚ��

void show() {
	for (int y = 1; y <= h; y++)
	{
		cout << '\n';
		for (int x = 1; x <= w; x++)
			cout << map[y][x]<<' ';
	}

	cout << '\n';
}

bool inrange(int y, int x) {
	return y > 0 && x > 0 && x <= w && y <= h;
}

int chtoin(char side) {
	if (side == 'E')
		return 1;
	if (side == 'N')
		return 0;
	if (side == 'S')
		return 2;
	if (side == 'W')
		return 3;
}

int turn(int side,char command) {
	
	if (command == 'L') {
		return (side + 3) % 4;
	}
	if (command == 'R') {
		return (side + 1) % 4;
	}

}

int getcommand(int robot, char command, int cnt) { // 1 ȸ��

	int tempy = r[robot].ry;
	int tempx = r[robot].rx;
	int side = r[robot].d;

	if (command == 'F') { //����

		while(cnt--) {

			 tempy += go[side][0];
			 tempx += go[side][1];

			if (!inrange(tempy, tempx)) { // out of range
				return -1;
			}
			else if (map[tempy][tempx] != 0) { // crash
				return map[tempy][tempx];
			}
		}

		map[r[robot].ry][r[robot].rx] = 0;
		map[tempy][tempx] = robot;
		r[robot].ry = tempy;
		r[robot].rx = tempx;


	}
	else { //���⼺
		
		cnt = cnt % 4;
		while(cnt--)
		side = turn(side, command);
		r[robot].d = side;
	}

	return 0;
}

int main() {
	cin >> w >> h; //1����~
	cin >> n >> m;
	r.push_back({ 0,0,'k' }); //����κ� 0��

	for (int x = 1; x <= n; x++)
	{
		int a, b; // ��ǥ
		char c; //����
		cin >> a >> b >> c;
		b = h - b + 1;
		r.push_back({ b, a, chtoin(c) });
		map[b][a] = x;
	}

	int res;

	for (int x = 0; x < m; x++) {
		int a, c; // �κ���ȣ,��ɾ�,�ݺ�Ƚ��
		char b;
		cin >> a >> b >> c;

		res = getcommand(a, b, c);

		if (res == 0)
			continue;
		else if (res == -1) {
			printf("Robot %d crashes into the wall", a);
			break;
		}
		else {
			printf("Robot %d crashes into robot %d", a, res);
			break;
		}

	}

	if(res == 0)
	cout << "OK";

	return 0;
}