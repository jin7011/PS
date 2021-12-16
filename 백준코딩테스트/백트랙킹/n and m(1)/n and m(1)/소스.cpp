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
			arr[cnt] = i; // pick i 니까 1~n의 숫자를 저장하려면 어쩔 수 없이 i = 0인덱스는 버리고 1~n까지 포함해서 ㄱ
			func(cnt + 1); //재귀 cnt++
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