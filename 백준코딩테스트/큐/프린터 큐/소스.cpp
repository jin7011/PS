#include <iostream>
#include <algorithm>
#include <queue>
#include <stdlib.h>

using namespace std;

typedef struct Data {
	int p;
	int a;
}Data;

int n, m,t;
queue <Data> que;

int main() {

	cin >> t;
	Data str[101];
	Data res;  //pop�� ���� str[m]�� ���ٸ� Ƚ���� ����� ����.

	while (t--) {

		cin >> n >> m;

		int cnt = 0;
		res = { 0 };
		str[0].a = 0;
		bool b[1001] = { 0 };
		while (que.size() != 0)
			que.pop();

		for (int x = 0; x < n; x++) {
			cin >> str[x].p;
		}

		for (int x = 1; x < n; x++) {
			str[x].a = (str[x - 1].a) + 1;
		}
		

		for (int x = 0; x < n; x++) 
			que.push(str[x]);
		
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		while (1) {

			for (int x = 0; x < n; x++) {//ù��°(back)�� p������ ū ���� �迭�� �ִٸ� que.front�� �ű�. 

				int i = que.front().p;

				if ( i < str[x].p && b[x] != 1) { // �ߺ�����.
					que.push(que.front());
					que.pop();
					x = -1;
				}
				
			}
				//�ߺôµ� ū���� ���ٸ� ������ p�� ���� ũ��, �װ��� pop���ָ� cnt++

				res = que.front();
				for (int x = 0; x < n; x++) {   //�� ���� ������ �迭���� �켱������ �ߺ����� �񱳵��� �ʰ� 0���� �����ش�.
					if (str[x].a == que.front().a && b[x] != 1) {
						b[x] = 1;
						break;
					}
				}
				que.pop();
				cnt++; // push�� ������ ���尻��

				if (res.a == str[m].a) {
					cout << cnt<<'\n';
					break;
				}
			
		}
	}


	return 0;
}