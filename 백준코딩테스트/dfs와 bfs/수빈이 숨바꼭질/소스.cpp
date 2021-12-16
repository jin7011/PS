#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

int n, k;
queue <pair<int,int>> que;
bool visited[100005];
int cnt = 0;

int step1(int x) {
	return x - 1;
}

int step2(int x) {
	return x + 1;
}

int step3(int x) {
	return 2 * x;
}

int choice(int x,int soo) { // �ɼǹ�ȣ�� �������� ������ġ

	if (x == 1) 
		return step1(soo);
	if (x == 2)
		return step2(soo);
	if (x == 3)
		return step3(soo);
	else 
		return 0;
}

int bfs() {

	while (!que.empty()) {

		int qf = que.front().first;
		int res = que.front().second;

		if (qf == k)
			return res;

		que.pop();
		
			for (int x = 1; x <= 3; x++) {

				int go = choice(x, qf);

				if (go >= 0 && go <= 100001) {
					if (!visited[go]) // �������ϴ°��� �����ʾҴ� ���� ��쿡��	
					{
						if (go == k)
							return res + 1;
						
						que.push({ go,res + 1 }); //�ɼǰ� ������ġ -> ������ġ�� return -> que�� ����
						visited[go] = true;
					}
				}
				
				
			}
		
	}
		
}

int main() {
	
	cin >> n >> k;
	que.push({ n,0 }); // ����������ġ que�� ����.
	visited[n] = 1;
	cnt = 1;

	cout << bfs();

	return 0;
}