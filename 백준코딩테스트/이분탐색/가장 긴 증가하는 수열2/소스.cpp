#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a[100001];
int dp[100001];
vector <int> vec;

int main() {
	int k;
	cin >> n;
	int o = n;
	int max = 0;
	vec.push_back(0);

	for(int x=0;x<n;x++){

		cin >> k;
		if (k > vec.back()) {
			vec.push_back(k);
			max++;
		}
		else {
			vector<int>::iterator iter = lower_bound(vec.begin(), vec.end(), k); //��ȯ���� �ε����� �ּҷ� ���⶧���� vec�� k, k������ k���� ū ���� ���� ��
			//�Ѹ���� vec�� �ε����� iterator������ ���� �װ� iter�� �޾Ƹ���.
		//	cout << "iter: " << *iter << '\n';
			*iter = k; //�޾Ƹ��� ���� ���ֹ����� k�� ȯ��
		}

		for (int x = 1; x < vec.size(); x++)
			cout << vec[x]<< ' ';

		cout << '\n';
	}

	cout << max;

	return 0;
}