#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <functional>
#include <iterator>
#include <string>

using namespace std;

set <string> res;
vector <string> vec[55];
string str;

int n;

using namespace std;

int main(){

	cin >> n;

	for(int x=0; x<n; x++) {
		cin >> str;
		vec[str.size()].push_back(str);
	}

	//cout << '\n';
	
	for (int x =1; x <= 50; x++) { // ���ڼ���� ���� 1~50��

		if (vec[x].size() == 0) continue; // ���ڼ��� ���� ����� ������ ������ �н�

		else { // �ִٸ� ������ �ִ� �ܾ� ��� �ߺ����� set�� �����ؼ� ���������� ���
			for (int i = 0; i < vec[x].size(); i++)
				res.insert(vec[x][i]); // set�� �ش� ���ڼ��� ���� �ڷḦ �ű��
		}

		for (auto iter = res.begin(); iter != res.end(); iter++) {  //set ���
			cout << *iter << '\n';
		}

		res.clear(); // ����Ŀ� set�� �������ڸ� ���� ����ش�

	}

	return 0;
}