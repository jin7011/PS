//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <deque>
//#include <functional>
//
//using namespace std; //벽 3개를 박을 수 있는 모든 경우의 수에 따른 최소결과값을 구한다.
//
//int res=0;
//
//vector <int> vec;
//queue <pair<int, int>> que;
//queue <pair<int, int>> s_que;
////priority_queue<int> pq;
////pair<int, int> p;
//
//int n, m;
//int map[5][11]; //기존의 그래프
//int s_map[5][11]; //저장할 그래프
////bool visited[5][11]; // 방문체크
//int cnt = 0;
//int go[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
//
//bool inrange(int a, int b) {
//    return a >= 0 && a < n && b >= 0 && b < m;
//}
//
//int check() {
//    cnt = 0;
//
//    for (int y = 0; y < n; y++)
//        for (int x = 0; x < m; x++) 
//            if (s_map[y][x] == 0)
//                cnt++;
//               
//    return cnt;
//}
//
//void bfs() { // 2부터 순차적으로 
//
//    for (int x = 0; x < n; x++) 
//        for (int y = 0; y < m; y++) 
//            s_map[x][y] = map[x][y];
//
//    queue <pair<int, int>> s_que = que;
//
//    while (!s_que.empty()) {
//
//       // int len = s_que.size();
//
//       // for (int Q = 0; Q < len; Q++) {
//            int tempx = s_que.front().second;
//            int tempy = s_que.front().first;
//            s_que.pop();
//
//            for (int x = 0; x < 4; x++) { // 4방향 탐색
//                int dx = tempx + go[x][0];
//                int dy = tempy + go[x][1];
//
//                if (inrange(dy, dx) && s_map[dy][dx] == 0) {                  
//                    s_map[dy][dx] = 2;
//                    s_que.push({ dy, dx });
//                }
//
//            }
//       // }
//    }
//
//}
//
//void func(int P) { // 벽 3개 랜덤하게 박는 함수
//     
//    if (P == 3) { //  벽 3개를 넣을때마다 재탐색
//       bfs(); //벽 3개친 s_map에 2를 모두 퍼뜨리는 함수
//       res = max(check(),res); //  결과값 -> 나중에 cout << *max_element(res,res+i) ;
//       return;
//    }
//
//    for (int y = 0; y < n; y++)
//        for (int x = 0; x < m; x++) {
//            if (map[y][x] == 0) {
//                map[y][x] = 1;         
//               
//                func(P+1);
//                
//                map[y][x] = 0;             
//
//            }
//        }
//
//}
//
//int main() {
//
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//
//    cin >> n >> m; //세로 가로
//
//    for (int y = 0; y < n; y++)
//        for (int x = 0; x < m; x++) {
//            cin >> map[y][x];
//          //  s_map[y][x] = map[y][x];
//        }
//
//        for (int y = 0; y < n; y++)
//            for (int x = 0; x < m; x++) 
//                if (map[y][x] == 2) 
//                    que.push({ y, x });
//                                        
//        func(0);
//
//      cout << res;
//
//    return 0;
//}

//3 ≤ N, M ≤ 8 -> n,m모두 3과8사이
//바이러스를 퍼뜨릴 때 bfs를 사용
#include <iostream>
#include <queue>
using namespace std;
#define MAX 8

int n, m, maxEmpty = 0;	//지도의 세로, 가로
int map[MAX][MAX], vmap[MAX][MAX];
int x[4] = { 1, -1, 0, 0 };
int y[4] = { 0, 0, -1, 1 };

queue<pair<int, int>> q;

void input() {
	int i, j, k, l;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> map[i][j];
			//바이러스면 Q에 넣음
			if (map[i][j] == 2) q.push({ i,j });
		}
	}
}

int count() {
	//0개수세기
	int i, j, safe = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (vmap[i][j] == 0) safe++;
		}
	}
	return safe;
}

void virus() {
	int a, b, i, j, nexta, nextb;

	queue<pair<int, int>> Q = q;
	//cmap유지위해 vmap에 복사
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			vmap[i][j] = map[i][j];
		}
	}

	while (!Q.empty()) {
		a = Q.front().first;
		b = Q.front().second;
		Q.pop();

		for (i = 0; i < 4; i++) {
			nexta = a + x[i];
			nextb = b + y[i];
			//좌표가 범위 내면
			if (nexta >= 0 && nexta < n && nextb >= 0 && nextb < m) {
				//바이러스감염도 안되었고 벽도 없으면
				if (vmap[nexta][nextb] == 0) {
					vmap[nexta][nextb] = 2;	//바이러스 감염
					Q.push({ nexta,nextb });
				}
			}
		}
	}

	maxEmpty = max(count(), maxEmpty);
}

void wall(int wcnt) {
	int i, j;
	if (wcnt == 3) {
		virus();
		return;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;	//벽 세움
				wall(wcnt + 1);
				map[i][j] = 0;	//벽 허물어 원상복귀
			}
		}
	}
}

int main() {
	int i, j;

	input();
	wall(0);
	cout << maxEmpty << endl;
	return 0;
}