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
	Data res;  //pop한 값이 str[m]과 같다면 횟수를 출력할 예정.

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

			for (int x = 0; x < n; x++) {//첫번째(back)의 p값보다 큰 값이 배열에 있다면 que.front로 옮김. 

				int i = que.front().p;

				if ( i < str[x].p && b[x] != 1) { // 중복제외.
					que.push(que.front());
					que.pop();
					x = -1;
				}
				
			}
				//쭉봤는데 큰값이 없다면 현재의 p가 가장 크고, 그것을 pop해주며 cnt++

				res = que.front();
				for (int x = 0; x < n; x++) {   //뺀 값은 참조할 배열에서 우선순위를 중복으로 비교되지 않게 0으로 맞춰준다.
					if (str[x].a == que.front().a && b[x] != 1) {
						b[x] = 1;
						break;
					}
				}
				que.pop();
				cnt++; // push된 순서를 저장갱신

				if (res.a == str[m].a) {
					cout << cnt<<'\n';
					break;
				}
			
		}
	}


	return 0;
}