#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str[1001];
string cp[1001];

int t;

bool judge() {

	for (int i = 0; i < t-1; i++) {
		for (int j = i+1; j < t; j++) {
			if (cp[i] == cp[j]) 
				return 0;	
		}
	}
	
	return 1;
}

int main() {

	cin >> t;

	for (int x = 0; x < t; x++)
		cin >> str[x];

	while (1) {

		if (!str[0].size()) break; // �� �����µ��� ���� �ȳ�����

		for (int x = 0; x < t; x++) {
			cp[x] += str[x].back(); // �ڿ��� copy�ؼ� �ٸ����� �����ϰ� ��
			str[x].pop_back(); // copy�� ������ ������ �����Ѵ�.
		}

		if (judge()) // cp �� ����� ������ ����̶��
			break;

	}

	cout << cp[0].size();

}