#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

typedef struct D {
	int M, N, H; //���μ��γ���
}D;

int map[101][101][101];
bool visited[101][101][101];
int date[101][101][101];

vector < vector <vector<int> > > vec;

queue <struct D> que;

D s; // ��ǥ(xyz)�� ���� ������ struct�� ����.
D temp;

//int dx[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[2] = {-1,1 };
int n, m, h;
int cnt = 0;

bool check = 0;


bool inrange(int a, int b,int c) {
	return a >= 0 && a < m && b >= 0 && b < n && c >= 0 && c < h;
}

void bfs() {
	
	while (!que.empty()) {

		int len = que.size();
		check = 0;

		for (int i = 0; i < len; i++) { // 121

			s = que.front();
			int x = s.M;
			int y = s.N;
			int z = s.H;  // ��ǥ�� temp ���� ����
			que.pop();
			
			for (int l = 0; l < 2; l++) { //���Ʒ� �Ǻ�
				int q = x;
				int w = y;
				int e = z + dz[l]; //-1 1

				if (inrange(q, w, e) && visited[q][w][e] == 0 && map[q][w][e] == 0) {
					visited[q][w][e] = true;
					s.H = e; s.M = q; s.N = w;  //s�� ��ǥ�� ����
					que.push(s);

					if (check == 0)
						check = 1;
				}
				 
			}
			
			for (int j = 0; j < 4; j++) {//�ڱ����� �����¿� �Ǻ�
					int q = x + dx[j];
					int w = y + dy[j];
					int e = z;

					if (inrange(q, w, e) && visited[q][w][e] == 0 && map[q][w][e] == 0) {
						visited[q][w][e] = true;
						s.H = e; s.M = q; s.N = w;
						que.push(s);

						if (check == 0)
							check = 1;
					}
			}
			
		}
		if (check == 1)
		{
			cnt++;
			check = 0;
		}
		else
			break;
	}

}

int main() {

	cin >> n >> m >> h; // ���μ��γ��� 5,3,2

	for(int z=0;z<h;z++)
	for (int x = 0; x < m; x++)
		for (int y = 0; y < n; y++)
			cin >> map[x][y][z];

	//for (int z = 0; z < h; z++) {
	//	cout << '\n';
	//	for (int x = 0; x < m; x++) {
	//		cout << '\n';
	//		for (int y = 0; y < n; y++)
	//			cout << map[x][y][z] << ' ';
	//	}
	//}

	for (int z = 0; z < h; z++)
	for (int x = 0; x < m; x++)   //�ʱ�ȭ
		for (int y = 0; y < n; y++) {
			visited[x][y][z] = 0;
		}

	for (int z = 0; z < h; z++)
		for (int x = 0; x < m; x++)   // 1�� ���� ������ que�� �̸� ����
			for (int y = 0; y < n; y++) {
				if (map[x][y][z] == 1) {
					s.H = z; s.M = x; s.N = y;
					que.push(s);
				}
			}

	bfs();

	bool ch = 0;

	for (int z = 0; z < h; z++)
		for (int x = 0; x < m; x++)
			for (int y = 0; y < n; y++)
			{
				if (visited[x][y][z] == 0 && map[x][y][z] == 0) {
					cout << -1;
					return 0;
				}
				else if (map[x][y][z] == 0)
					ch = 1;
			}

	if (ch == 0)
		cout << 0;
	else
	cout << cnt;

	return 0;
}