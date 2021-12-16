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

int go[4][2] = { {1,0},{-1,0},{0,1},{0,-1} }; // 4�� üũ
int res;

int ctoi(char ch) { 
	int a = (int)ch - 65; // 0~25 �迭���� -> hash ��� �� ����
	return a;
}

bool inrange(int y, int x) {
	return y >= 0 && x >= 0 && y < h&& x < w;
}

void dfs(int y, int x ,bool check[],int D) {
	
	//exit condition
	if (!inrange(y, x)) 
		return; // ���� ���̰�, �ߺ��Ǵ� ���İ� �ִٸ� �ٷ� return;
	else if(check[map[y][x]])
		return;

	check[map[y][x]] = 1; // ����üũ[ch->int] -> bool üũ 
	res = max(D, res); //dfs�� ���������� �� �� ���� �������� ũ�ٸ� �װ����� reset 

	//4�� check  
	//��ͷ� ®�⶧���� ���ư��� check�� �������� ���ư��� �κ�Ȱ��. -> ������ check�� �Լ��� ����.
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