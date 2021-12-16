#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int go[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//int goy[2] = { 0,1 };
//int gox[2] = { 1,0 };

int h, w,k;
int a, b,c,d;
int cnt = 0;
int Zcnt;
bool map[101][101];

queue <pair<int, int>> que;
vector <int> res;
priority_queue <int> pq;

bool inrange(int y, int x) {
	return y > 0 && y <= h&& x > 0 && x <= w;
}
//
//bool squarerange(int y, int x, int x1, int y1, int x2, int y2) { //(y,x)좌표가 x1,y1 과 x2,y2안에 있는가?
//	return y >= y1 && y <= y2 && x >= x1 && x <= x2;
//}
//
//void sqbfs(int y1, int x1,int y2, int x2) {
//
//	que.push({ y1,x1 });
//	map[y1][x1] = 1;
//
//	while (!que.empty()) {
//
//		int tempy = que.front().first;
//		int tempx = que.front().second;
//
//		que.pop();
//
//		for (int x = 0; x < 2; x++) { //오른쪽,아래
//
//			int dy = tempy + goy[x];
//			int dx = tempx + gox[x];
//
//			if (squarerange(dy,dx,x1,y1,x2,y2) && inrange(dy,dx)) {
//				if (map[dy][dx] == 0) {
//					map[dy][dx] = 1;
//					que.push({ dy,dx });
//				
//				}
//				else if (map[dy][dx] == 1) {
//					que.push({ dy,dx });
//				}
//			}
//		}
//	}
//}
	

int bfs(int y,int x) {

	Zcnt = 1;
	que.push({ y,x });
	map[y][x] = 1;

	while (!que.empty()) {

		int tempy = que.front().first;
		int tempx = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++) {
			int dy = tempy + go[i][1];
			int dx = tempx + go[i][0];

			if (inrange(dy, dx) && map[dy][dx] == 0 ) {
				Zcnt++;
				map[dy][dx] = 1;
				que.push({ dy,dx });
			}
		}
	}
	return Zcnt;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> h >> w>> k;

	while (k--) {
		cin >> a >> b >> c >> d;
		
		for (int y = b+1; y <= d; y++)
			for (int x = a+1; x <= c; x++)
				map[y][x] = 1;
	}
	
	for(int y=1; y<=h ; y++) 
		for (int x = 1; x <= w; x++) {
			if (map[y][x] == 0) {
				pq.push(-1 * bfs(y, x));
				cnt++;
			}
		}

	cout << cnt <<'\n';
	if (pq.size() > 0) {
		while (!pq.empty()) {
			cout << -1*pq.top()<<' ';
			pq.pop();
		}
	}
	else
		cout << 0;

	return 0;
} 