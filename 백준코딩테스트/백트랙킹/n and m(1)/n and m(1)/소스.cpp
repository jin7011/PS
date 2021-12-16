#include <iostream>
#include <vector>
using namespace std;

const int MAX = 8 + 1;

int N, M;
int arr[MAX];
bool visited[MAX];

void func(int cnt)
{
	if (cnt == M) // exit condition
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {

		//int b = !visited[i];
		if (!visited[i]) // visited check
		{
			visited[i] = true;
			arr[cnt] = i; // pick i �ϱ� 1~n�� ���ڸ� �����Ϸ��� ��¿ �� ���� i = 0�ε����� ������ 1~n���� �����ؼ� ��
			func(cnt + 1); //��� cnt++
			visited[i] = false;
		}

	}
}

int main(void)
{
	cin >> N >> M;

	func(0);
	return 0;
}