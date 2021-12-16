#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

int h, w;
int map[21][21]; 
bool check[10000];
char ch;

int go[4][2] = { {1,0},{-1,0},{0,1},{0,-1} }; // 4방 체크
int res;

int ctoi(char ch) { 
	int a = (int)ch - 65; // 0~25 배열저장 -> hash 사용 할 예정
	return a;
}

bool inrange(int y, int x) {
	return y >= 0 && x >= 0 && y < h&& x < w;
}

void dfs(int y, int x ,bool check[],int D) {
	
	//exit condition
	if (!inrange(y, x)) 
		return; // 범위 밖이고, 중복되는 알파가 있다면 바로 return;
	else if(check[map[y][x]])
		return;

	check[map[y][x]] = 1; // 알파체크[ch->int] -> bool 체크 
	res = max(D, res); //dfs가 끝까지갔을 때 그 값이 이전보다 크다면 그것으로 reset 

	//4방 check  
	//재귀로 짰기때문에 돌아가면 check가 이전으로 돌아가는 부분활용. -> 쓰였던 check를 함수에 전달.
	dfs(y + 1, x, check,D+1);
	dfs(y, x + 1, check,D+1);
	dfs(y - 1, x, check,D+1);
	dfs(y, x - 1, check,D+1);

	check[map[y][x]] = 0;
	
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> h >> w;

	for(int y=0; y<h; y++)
		for (int x = 0; x < w; x++) {
			cin >> ch;
			map[y][x] = ctoi(ch);
		}

	dfs(0,0,check,1);

	cout << res; // print maxres
	cout << '\n';

	return 0;
}