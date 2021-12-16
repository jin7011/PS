#include <iostream>

using namespace std;

typedef struct rgb {
	int r, g, b;
}rgb;

rgb a[1001]; //�� ���� rgb ����ǥ

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

int SetRes_Sum(int arr[],int n) { //ġȯ

	int s = 0;
	for (int x = 1; x <= n; x++) { //��� ���� ����� ����(rgb)�� �������� ġȯ�Ѵ�.
		if (arr[x] == 1) res[x] = a[x].r;
		if (arr[x] == 2) res[x] = a[x].g;
		if (arr[x] == 3) res[x] = a[x].b;
		s += res[x];
	}
	return s;

}

void func(int n,int cnt) {

	if (cnt == n+1) { // 121,123,131,132 , 212,213,231,232 .... //i���� ���� ������ ��� �������� ��� ���� �����Ѵ�.
		//res[]�� arr���ΰ��� �������� ġȯ(�Լ����)�ؼ� �������. ���� ���� ����ؼ� �� ����(�Լ�)
		sum[k] = SetRes_Sum(arr, n);
		k++;
		return;
	}

	for (int x = 1; x <= 3; x++) { // ���� �� �ִ� �� case ��üŽ��
		if (cnt >= 2 && x == arr[cnt - 1]) continue; // 1���� ������� �� �ڷδ� ������ ������ continue
		arr[cnt] = x;  //�̷��ԵǸ� cnt�� ����ȣ�� ��. a[0]=0�� ����.
		func(n,cnt + 1);
	}

}

int getmincost(int i, int choice) {

	if (i > n) return 0; // �� �������� ū i �� ������ return 0 // exit condition

	if (cashe[i][choice] != -1) return cashe[i][choice];

	int res_r = 123123;
	int res_g = 123123;
	int res_b = 123123;

	if (choice != 1) // ������ 1�� �ƴҶ�, ������ 1�� Ȯ������ ������ ���� ���Ѵ�.
		res_r = a[i].r + getmincost(i + 1, 1);
	if(choice != 2) 
		res_g = a[i].g + getmincost(i + 1, 2);
	if (choice != 3)
		res_b = a[i].b + getmincost(i + 1, 3);

	return cashe[i][choice] = min(res_r, min(res_g, res_b));

}

int main() {

	cin >> n; //�� ����

	for (int x = 1; x <= n; x++) //1�� ������ n�������� rgb ���� ����.  0����
		cin >> a[x].r >> a[x].g >> a[x].b;

	for (int y = 0; y < 1001; y++)
		for (int x = 0; x < 4; x++)
			cashe[y][x] = -1;

	//func(n,1);
	
	cout << getmincost(1, 0);

	//cout << min(sum, n);

	return 0;
}