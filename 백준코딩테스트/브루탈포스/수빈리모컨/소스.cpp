#include<iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <functional>
#include <queue>

using namespace std;

int n, m,cnt,a;
bool arr[10];
int ans;

void go(int val, int cnt) {

	if (val) ans = min(ans, abs(val - n) + cnt); // val != 0 일때 (현재 ans)와 ( (현재채널 - 목표채널) +더 눌러야하는 버튼 중 ) 최소
	if (val > n) return;

	for (int i = val == 0; i < 10; i++) {//처음 누른 버튼(val)이 0 이라면 i는 1부터 시작할 수 있는 고오급스킬**
		if (arr[i] != 1) 
			go(val * 10 + i, cnt + 1);// 고장난 버튼을 제외하고 가능한 버튼을 먼저 눌러본다.
	}
}

int main() {
	cin >> n >> m;

	for (int x = 0; x < m; x++)
	{
		cin >> a;
		arr[a] = 1;
	}
	
	ans = abs(n - 100); // abs(목표채널 - 현재채널) => +,- 버튼눌러야하는 횟수
	if(arr[0] == 0) // 0 버튼이 살아있을 경우
		ans = min(ans, n+1); 

	go(0, 0);

	cout << ans;
	
	return 0;
}