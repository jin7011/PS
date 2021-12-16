//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <deque>
//#include <functional>
//
//using namespace std; //�� 3���� ���� �� �ִ� ��� ����� ���� ���� �ּҰ������ ���Ѵ�.
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
//int map[5][11]; //������ �׷���
//int s_map[5][11]; //������ �׷���
////bool visited[5][11]; // �湮üũ
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
//void bfs() { // 2���� ���������� 
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
//            for (int x = 0; x < 4; x++) { // 4���� Ž��
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
//void func(int P) { // �� 3�� �����ϰ� �ڴ� �Լ�
//     
//    if (P == 3) { //  �� 3���� ���������� ��Ž��
//       bfs(); //�� 3��ģ s_map�� 2�� ��� �۶߸��� �Լ�
//       res = max(check(),res); //  ����� -> ���߿� cout << *max_element(res,res+i) ;
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
//    cin >> n >> m; //���� ����
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

//3 �� N, M �� 8 -> n,m��� 3��8����
//���̷����� �۶߸� �� bfs�� ���
#include <iostream>
#include <queue>
using namespace std;
#define MAX 8

int n, m, maxEmpty = 0;	//������ ����, ����
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
			//���̷����� Q�� ����
			if (map[i][j] == 2) q.push({ i,j });
		}
	}
}

int count() {
	//0��������
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
	//cmap�������� vmap�� ����
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
			//��ǥ�� ���� ����
			if (nexta >= 0 && nexta < n && nextb >= 0 && nextb < m) {
				//���̷��������� �ȵǾ��� ���� ������
				if (vmap[nexta][nextb] == 0) {
					vmap[nexta][nextb] = 2;	//���̷��� ����
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
				map[i][j] = 1;	//�� ����
				wall(wcnt + 1);
				map[i][j] = 0;	//�� �㹰�� ���󺹱�
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