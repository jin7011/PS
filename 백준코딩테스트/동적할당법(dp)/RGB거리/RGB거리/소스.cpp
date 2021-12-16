#include <iostream>

using namespace std;

typedef struct rgb {
	int r, g, b;
}rgb;

rgb a[1001]; //각 집의 rgb 가격표

int res[1001] = { 0 };
int m = 0;
int arr[1001] = { 0 };
int k = 0;
int sum[6010] = { 0 };

int n = 0;
int choice = 0;
int cashe[1001][4];


int min2(int a[],int n) {

	int len = 6 * (n - 1);
	m = a[0];
	for (int x = 1; x < len; x++){
		if (a[x] < m) {
			m = a[x];
		}
	}
	return m;
}

int min(int a, int b) {

	if (a < b) return a;
	else return b;

}

int SetRes_Sum(int arr[],int n) { //치환

	int s = 0;
	for (int x = 1; x <= n; x++) { //모든 집에 저장된 숫자(rgb)를 가격으로 치환한다.
		if (arr[x] == 1) res[x] = a[x].r;
		if (arr[x] == 2) res[x] = a[x].g;
		if (arr[x] == 3) res[x] = a[x].b;
		s += res[x];
	}
	return s;

}

void func(int n,int cnt) {

	if (cnt == n+1) { // 121,123,131,132 , 212,213,231,232 .... //i개의 집의 색깔이 모두 정해지는 경우 값을 저장한다.
		//res[]에 arr내부값을 가격으로 치환(함수사용)해서 집어넣자. 그후 합을 계산해서 또 넣자(함수)
		sum[k] = SetRes_Sum(arr, n);
		k++;
		return;
	}

	for (int x = 1; x <= 3; x++) { // 나올 수 있는 색 case 전체탐색
		if (cnt >= 2 && x == arr[cnt - 1]) continue; // 1부터 순서대로 그 뒤로는 이전과 같으면 continue
		arr[cnt] = x;  //이렇게되면 cnt가 집번호가 됌. a[0]=0은 버려.
		func(n,cnt + 1);
	}

}

int getmincost(int i, int choice) {

	if (i > n) return 0; // 집 갯수보다 큰 i 가 들어오면 return 0 // exit condition

	if (cashe[i][choice] != -1) return cashe[i][choice];

	int res_r = 123123;
	int res_g = 123123;
	int res_b = 123123;

	if (choice != 1) // 이전이 1이 아닐때, 다음을 1로 확정지어 나오는 수를 구한다.
		res_r = a[i].r + getmincost(i + 1, 1);
	if(choice != 2) 
		res_g = a[i].g + getmincost(i + 1, 2);
	if (choice != 3)
		res_b = a[i].b + getmincost(i + 1, 3);

	return cashe[i][choice] = min(res_r, min(res_g, res_b));

}

int main() {

	cin >> n; //집 갯수

	for (int x = 1; x <= n; x++) //1번 집부터 n번집까지 rgb 가격 저장.  0버려
		cin >> a[x].r >> a[x].g >> a[x].b;

	for (int y = 0; y < 1001; y++)
		for (int x = 0; x < 4; x++)
			cashe[y][x] = -1;

	//func(n,1);
	
	cout << getmincost(1, 0);

	//cout << min(sum, n);

	return 0;
}