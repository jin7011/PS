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
			vector<int>::iterator iter = lower_bound(vec.begin(), vec.end(), k); //반환값이 인덱스의 주소로 들어가기때문에 vec에 k, k없으면 k보다 큰 가장 작은 수
			//한마디로 vec의 인덱스를 iterator값으로 보냄 그걸 iter가 받아먹음.
		//	cout << "iter: " << *iter << '\n';
			*iter = k; //받아먹은 값은 없애버리고 k로 환승
		}

		for (int x = 1; x < vec.size(); x++)
			cout << vec[x]<< ' ';

		cout << '\n';
	}

	cout << max;

	return 0;
}